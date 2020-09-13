#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int B = 11;
const int A = 4;

int n;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    string opt;
    int a, b;
    int k;

    while (cin >> n) {
        k = 0;
        priority_queue <pair<int, int> > doc[A];
        for (int i=0; i<n; i++) {
            cin >> opt;
            if (opt == "IN") {
                cin >> a >> b;
                k++;
                doc[a].push(make_pair(b, -k));
            } else {
                cin >> a;
                if (doc[a].empty()) {
                    cout << "EMPTY\n";
                } else {
                    cout << -doc[a].top().second << "\n";
                    doc[a].pop();
                }
            }
        }
    }

    return 0;
}