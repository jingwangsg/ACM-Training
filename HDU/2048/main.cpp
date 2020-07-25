#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

const int N = 21;

typedef long long ll;

ll n, f[N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        memset(f, 0, sizeof(f));
        if (n < 2) {
            cout << "0.00%" << endl;
            continue;
        }
        f[2] = 1;
        for (int i=3; i<=n; i++) {
            f[i] = (i-1) * (f[i-1] + f[i-2]);
        }
        double rate = f[n];
        for (ll i=2; i<=n; i++) {
            rate /= i;
        }
        cout << fixed << setprecision(2) << rate * 100 << "%" << endl;
    }
    
    return 0;
}