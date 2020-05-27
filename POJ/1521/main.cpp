#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;

int cnt[30];

bool cmp(int a, int b) {return a > b;}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    while (cin >> str && str != "END") {
        memset(cnt, 0, sizeof(cnt));
        int len = str.length();
        for (int i=0; i<len; i++) {
            if (str[i] == '_') cnt[26]++;
            else cnt[str[i] - 'A'] ++;
        }
        sort(cnt, cnt+27, cmp);
        int ans = 0;
        int enc = 1;
        for (int i=0; i<=26; i++) {
            if (cnt[i] != 0) {
                ans += cnt[i] * enc;
                cout << cnt[i] << " " << enc << endl;
                if (enc != 1 && (i == 26 || cnt[i+1] == 0)) ans -= cnt[i];
                enc++;
            }
        }
        cout << len * 8 << " " << ans << " ";
        cout << fixed << setprecision(1) << (double)(len*8) / ans << endl;
    }
    return 0;
}