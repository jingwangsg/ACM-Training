#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 200010;

int n;
int cnt[N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    cin >> T;
    int uniq_skill;
    int max_cnt;
    while (T--) {
        int x;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        uniq_skill = 0;
        max_cnt = 0;
        for (int i=0; i<n; i++) {
            cin >> x;
            if (cnt[x] == 0) uniq_skill ++;
            cnt[x] ++;
            max_cnt = max(cnt[x], max_cnt);
        }
        int tmp, ans=0;
        // cout << uniq_skill << " " << max_cnt << endl;
        tmp = min(uniq_skill, max_cnt-1);
        ans = max(ans, tmp);
        tmp = min(uniq_skill-1, max_cnt);
        ans = max(ans, tmp);
        cout << ans << endl;
    }

    return 0;
}