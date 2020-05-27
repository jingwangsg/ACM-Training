#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;

const double eps = 1e-6;
int n, V, W100;
double W;
double con[110];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> V >> W100;
        W = W100 / 100.0;
        int tmp;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            con[i] = (double) tmp / 100;
        }
        sort(con, con+n);
        double sum = 0;
        int k;
        for(k=0; k<n; k++) {
            if ( (sum + con[k]) / (k+1) > W) break;
            sum += con[k];
        }
        if (k == 0) cout << "0 0.00" << endl;
        else {
            cout << k * V << " ";
            cout << fixed << setprecision(2) << sum / k << endl;
        }
    }

    return 0;
}