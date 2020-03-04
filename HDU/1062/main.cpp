#include<iostream>
using namespace std;

int n;
string str;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    getline(cin, str);
    for (int i=0; i<n; i++) {
        getline(cin, str);
        int len = str.size();
        string cur_word = "";
        string cur_str = "";
        for (int i=0; i<len; i++) {
            if (str[i] == ' ') {
                cur_str += cur_word + " ";
                cur_word = "";
            }else cur_word = str[i] + cur_word;
        }
        cur_str += cur_word;
        cout << cur_str << endl;
    }
    
    return 0;
}