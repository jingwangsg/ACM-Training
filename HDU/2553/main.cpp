#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

int n;
int ans[11];
bool col[11], diag[21], rev_diag[21];

void dfs(int i) {
    if (i == n+1){
        ans[n] ++;
        return;
    }
    for (int j=1; j<=n; j++) {
        if (!col[j] && !diag[i + j] && !rev_diag[n + i - j]) {
            col[j] = true;
            diag[i + j] = true;
            rev_diag[n + i - j] = true;
            dfs(i+1);
            col[j] = false;
            diag[i + j] = false;
            rev_diag[n + i - j] = false;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int ans[11] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
    for (n=1; n<=10; n++) {
        ans[n] = 0;
        memset(col, 0, sizeof(col));
        memset(diag, 0, sizeof(diag));
        memset(rev_diag, 0, sizeof(rev_diag));
        dfs(1);
    }

    int n;
    while (cin >> n && n) {
        cout << ans[n] << endl;
    }

    return 0;
}