#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;
const int INF = 0x7ffffff;
int n, m;
int sum[N], card[N];
int dp[N];

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));

        cin >> n >> m;
        int tmp;
        for (int i=1; i<=n; i++) {
            cin >> card[i];
        }
        for (int i=1; i<=n; i++) {
            sum[i] = sum[i-1] + card[n-i+1];
        }
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            dp[i] = -INF;
            for (int j=1; j<=m; j++) {
                if (i - j < 0) break;
                dp[i] = max(sum[i] - dp[i-j], dp[i]);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}