#include<iostream>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n<=2) {
            cout << "0" << endl;
        } else {
            if (n % 2 == 0) cout << (int)(n/2) - 1 << endl;
            else cout << (int)(n/2) << endl;
        }

    }

    return 0;
}