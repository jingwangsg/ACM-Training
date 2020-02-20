#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

string str[4];
int cnt[26];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    for (int i=0; i<4; i++) getline(cin, str[i]);
    int maxline = 0;

    memset(cnt, 0, sizeof(cnt));
    
    for (int i=0; i<4; i++) {
        string cur_str = str[i];
        int len = cur_str.length();
        for (int j=0; j<len; j++) {
            char cur_ch = cur_str[j];
            if (cur_ch >= 'A' && cur_ch <= 'Z'){
                cnt[cur_ch - 'A'] ++;
                maxline = max(maxline, cnt[cur_ch - 'A']);
            }
        }
    }


    for (int i=maxline; i>0; i--) {
        string curline = "";
        for (int j=0; j<26; j++) {
            if (cnt[j] >= i) curline += "*"; else curline += " ";
            curline += " ";
        }
        while (curline[curline.length()-1] == ' ') {
            curline = curline.substr(0, curline.length()-1);
        }
        cout << curline;
        cout << "\n";
    }

    for (char ch='A'; ch<'Z'; ch++) cout << ch << " ";
    cout << "Z";

    return 0;
}