#include <stdio.h>
#include <math.h>

#define eps 0.0000000001

typedef struct s_point {
    double x, y;
} Point;

typedef struct s_line {    // line: a*x + b*y + c = 0
    double a, b, c;
} Line;

int equal(double x, double y) { 
    if (fabs(x - y) < eps) {
        return 1;
    }
    return 0;
}

// calculate the perpendicular bisector of line defined by p1 and p2
Line bisector(Point p1, Point p2) {  
    Line line;
    if (equal(p1.x, p2.x)) {
        line.a = 0.0, line.b = 1.0, line.c = - (p1.y  + p2.y) / 2.0;
    } else if (equal(p1.y, p2.y)) {
        line.a = 1.0, line.b = 0.0, line.c = - (p1.x + p2.x) / 2.0;
    } else {
        double k = - (p2.x - p1.x) / (p2.y - p1.y);
        double cx = (p1.x + p2.x) / 2.0;
        double cy = (p1.y + p2.y) / 2.0;
        double b = cy - k * cx;
        line.a = k, line.b = -1, line.c = b;
    }
    return line;
}

Point ps[200];
int n = 0, max = 1;

// count the number of points in the circle whose center is c
int count(Point c) {
    int i, ret = 0;
    for (i = 0; i < n; i++) {
        double dx = ps[i].x - c.x;
        double dy = ps[i].y - c.y;
        double d = sqrt(dx*dx + dy*dy);
        if (d > 2.5) continue; // the radius equals 2.5
        ret++;
    }
        // printf("[C]\t%.2lf %.2lf %d\n", c.x, c.y, ret);
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    double x, y; int i, j;
    while (scanf("%lf%lf", &x, &y) != EOF) {
        ps[n].x = x, ps[n].y = y;
        n++;
    }
    
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            double dx = ps[j].x - ps[i].x;
            double dy = ps[j].y - ps[i].y;
            double dd = dx * dx + dy * dy;
            int tmp1, tmp2;
            if (dd > 25.0) continue;
            // printf("%.2lf %.2lf %.2lf %.2lf\n",ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            if (equal(dd, 25.0)) {
                Point center; 
                center.x = (ps[i].x + ps[j].x) / 2.0;
                center.y = (ps[i].y + ps[j].y) / 2.0;
                // printf("#1\n");
                tmp1 = count(center);
            } else {
                // printf("#2\n");
                Line line = bisector(ps[i], ps[j]);
                double d = sqrt(6.25 - dd / 4.0);
                double em = sqrt(line.a * line.a + line.b * line.b);
                double ex = line.b / em;    
                double ey = -line.a / em;
                double cx = (ps[i].x + ps[j].x) / 2.0;
                double cy = (ps[i].y + ps[j].y) / 2.0;
                Point center; 
                center.x = cx + d * ex;
                center.y = cy + d * ey;
                tmp1 = count(center);
            
                center.x = cx - d * ex;
                center.y = cy - d * ey;
                tmp2 = count(center);
            
                tmp1 = tmp1 > tmp2 ? tmp1 : tmp2;
            }
            max = max < tmp1 ? tmp1 : max;
        }
    }
    printf("%d\n", max);
    return 0;
}