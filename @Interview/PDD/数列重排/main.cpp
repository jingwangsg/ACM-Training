#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int dp[1<<25];
int dp_solution[1<<25];


void Solver(int n) {
    memset(dp, 0, sizeof(dp));
    dp[(1<<(n-1)) | 1] = 1;
    dp_solution[1<<(n-1) | 1] = n-1;
    for (int state = 1; state < (1<<n); state++) {
        if (dp[state]) continue;
        int sum = 0;
        for (int i=0; i<n; i++) if(state & (1<<i)) sum += (i+1);
        for (int i=0; i<n; i++) {
            if (!(state & (1 << i))) continue;
            if (dp[state^(1 << i)] && (sum - (i+1)) % (i+1) == 0) {
                dp[state] = 1;
                dp_solution[state] = i;
            }
        }
    }
    int state = (1<<n) - 1;
    int ans[n+1];
    int cur_ans;
    memset(ans, 0, sizeof(ans));
    if (dp[state]) {
        while(true) {
            cur_ans = dp_solution[state] + 1;
            ans[++ans[0]] = cur_ans;
            if (cur_ans == n) {
                ans[++ans[0]] = 1;
                break;
            }
            state ^= (1 << (cur_ans-1));
        }
        for (int i=ans[0]; i>=1; i--) cout << ans[i] << " "; cout << endl;
    }else cout << "false" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i=3;i<=30;i++){
        Solver(i);
    }
    return 0;
}