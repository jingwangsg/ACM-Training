#include<iostream>
#include<algorithm>
using namespace std;

int arr[3];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    cin >> T;

    while (T--) {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        if (arr[2] == arr[1]) {
            cout << "YES\n";
            cout << arr[2] << " " << arr[0] << " " << arr[0] << endl;
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}