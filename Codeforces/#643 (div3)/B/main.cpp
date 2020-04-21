#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int N = 2010;

int n, a, b;
char str[N];
int exist[27];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    int l,r;
    char cur_char;
    cin >> T;

    while (T--) {
        cin >> n >> a >> b;
        memset(str, 0, sizeof(str));
        memset(exist, 0, sizeof(exist));
        for (int i=0; i<b; i++) cur_char =  'a' + i, str[i] = cur_char, exist[cur_char-'a'] ++;
        for (int i=b; i<a; i++) cur_char = 'a' + b - 1, str[i] = cur_char, exist[cur_char-'a'] ++;
        l=0; r=a;
        while (r < n) {
            // cout << l << endl;
            exist[str[l]-'a']--;
            if (exist[str[l]-'a'] == 0) str[r] = str[l], exist[str[l]-'a'] ++;
            else {
                for (int t=0; t<26; t++) if (!exist[t]) {
                    str[r] = 'a' + t;
                    exist[t]++;
                    break;
                }
            }
            l++;
            r++;
        }
        str[n] = '\0';
        cout << str << endl;
    }

    return 0;
}