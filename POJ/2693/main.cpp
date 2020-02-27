#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define sqrSum(x, y) ((x) * (x) + (y) * (y)) 
const int N = 210;
const double eps = 1e-10;

struct node {
    void set_value(double x_, double y_) {
        this->x = x_;
        this->y = y_;
    }
    double x, y;
}node_set[N]; int sz;

int count(double x, double y) {
    int ret = 0;
    for (int i=0; i<sz; i++) {
        double dist2 = sqrSum(x - node_set[i].x, y - node_set[i].y);
        if (dist2 < 2.5 * 2.5 + eps) ret++;
    }
    // printf("[C]\t%.2lf %.2lf %d\n", x, y, ret);
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(false);
    sz = 0;
    double x, y;
    int ans = 1;
    while (cin >> x >> y) node_set[sz++].set_value(x, y);
    for (int i=0; i<sz; i++) {
        for (int j=i+1; j<sz; j++) {
            double x1 = node_set[i].x, x2 = node_set[j].x;
            double y1 = node_set[i].y, y2 = node_set[j].y;
            double dist2 = sqrSum(x1-x2, y1-y2);

            if (dist2 > 25.0 + eps) continue;
                // printf("%.2lf %.2lf %.2lf %.2lf\n", x1, y1, x2, y2);
            int cnt = 0;
            // printf("[D]\t%.2lf\n",dist2);
            if (abs(dist2 - 25.0) < eps){
                cnt = count((x1+x2)/2, (y1+y2)/2);
            } else {
                node vec;
                double mod = sqrt(dist2);
                double vec_len = sqrt(2.5*2.5 - dist2 / 4.0);
                vec.set_value((y1 - y2) / mod, (x2 - x1) / mod);
                vec.x *= vec_len; vec.y *= vec_len;
                double mid_x = (x1 + x2) / 2, mid_y = (y1 + y2) / 2;
                cnt = max(cnt, count(mid_x + vec.x, mid_y + vec.y));
                cnt = max(cnt, count(mid_x - vec.x, mid_y - vec.y));
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}