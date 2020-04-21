#include<iostream>
using namespace std;

const int N = 100010;

char arr[N];

int main() {
    // freopen("in.txt", "r", stdin);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            arr[i] -= '0';
            if (i > 0 && arr[i-1] == 0 && arr[i] == 0) arr[i-1] = 1;
        }
        for (int i=0; i<n; i++) cout << (char)(arr[i] + '0');
        cout << endl;
    }
    
    return 0;
}