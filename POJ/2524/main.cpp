#include<iostream>
using namespace std;
const int N = 50010;

int n, m;
int fa[N];

int get_fa(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = get_fa(fa[x]);
}

void join(int x, int y) {
    if (get_fa(x) != get_fa(y)) fa[get_fa(x)] = get_fa(y);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int x, y;
    int case_idx = 0;
    ios::sync_with_stdio(false);

    while (cin >> n >> m && n && m) {
        case_idx ++;
        for (int i=0; i<n; i++) fa[i] = i;
        for (int i=0; i<m; i++) {
            cin >> x >> y;
            x--; y--;
            join(x, y);
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (fa[i] == i) cnt ++;
        }
        cout << "Case " << case_idx<< ": " << cnt << endl;
    }

    return 0;
}