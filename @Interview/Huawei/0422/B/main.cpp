#include<iostream>
#include<iomanip>
using namespace std;

int arr[50000010], sz;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    //if 5b ba -> 5a    if 5b bb -> 5b
    //if 91 186 -> 90   if 91 187 -> 91
    //cin >> hex >> ...
    //cout << hex << setfill('0') << setw(2) << ...;

    int x;
    sz = 0;
    int last_sep;
    int cnt = 0;
    cin >> hex >> x; //read first 5a
    arr[sz++] = x;
    last_sep = 0;
    while (cin >> hex >> x) {
        if (x == 90) {
            //check
            if (arr[sz-1] != cnt - 1) {
                // cout << "A" << endl;
                // cout << cnt << endl;
                //test failed
                sz = last_sep + 1;
            }
            else {
                //test succeed
                // cout << "B" << endl;
                // cout << cnt << endl;
                arr[sz++] = x;
                last_sep = sz - 1;
            }
            cnt = 0;
        }else{
            if (x == 186 && arr[sz-1] == 91) cnt --;
            if (x == 187 && arr[sz-1] == 91) cnt --;
            arr[sz++] = x;
            cnt ++;
        }
    }
    for(int i=0; i<sz; i++) cout << hex << setfill('0') << setw(2) << arr[i] << " ";
    cout << endl;

    return 0;
}