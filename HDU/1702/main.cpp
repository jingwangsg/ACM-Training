#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int arr[N];
int head, tail;
string mode;
int n;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;
    string opt;
    int val;

    while (T--) {
        cin >> n >> mode;

        head = tail = 0;

        for (int i=0; i<n; i++) {
            cin >> opt;
            if (opt == "IN") {
                cin >> val;
                arr[tail++] = val;
            } else {
                if (head == tail) {
                    cout << "None\n";
                    continue;
                }
                if (mode == "FILO") {
                    cout << arr[--tail] << "\n";
                } else {
                    cout << arr[head++] << "\n";
                }
            }
        }
    }

    return 0;
}