#include<iostream>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int n, l;

int main() {
    // freopen("in.txt", "r", stdin);
    ll ans;
    while (cin >> n >> l && (n || l)) {
        ans = 0;
        ll cum_n = 1;
        for (int i=1; i<=l; i++) {
            cum_n = (cum_n * n) % MOD;
            ans = (ans + cum_n) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}