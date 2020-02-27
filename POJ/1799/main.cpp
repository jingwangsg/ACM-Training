#include<cstdio>
#include<cmath>
using namespace std;
#define pi (acos(-1))

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    double R, r;
    int n;

    while(~scanf("%d", &T)) {
        for (int idx=1; idx<=T; idx++) {
            scanf("%lf%d", &R, &n);
            r = R * sin(pi/n) / (1.0 + sin(pi/n));
            printf("Scenario #%d:\n%.3lf\n\n", idx, r);
        }
    }
    return 0;
}