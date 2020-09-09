#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int arr[N];
int head, tail;
string mode;
int n;

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;
    string opt;
    int val;

    while (T--) {
        cin >> n >> mode;

        cin >> opt;
        if (opt == "IN") {
            cin >> val;
            arr[tail++] = val;
        } else {
            if (mode == "FIFO") {
                cout << arr[--tail] << "\n";
            } else {
                cout << arr[head++] << "\n";
            }
        }
    }

    return 0;
}