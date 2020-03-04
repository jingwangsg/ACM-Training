#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010;

int fa[N];
int m, n;

int get_fa(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = get_fa(fa[x]);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    int x, y;
    int cnt;

    while (T--) {
        cnt = 0;
        cin >> n >> m;
        for (int i=0; i<n; i++) fa[i] = i;
        for (int i=0; i<m; i++) {
            cin >> x >> y;
            x--; y--;
            if (get_fa(x) != get_fa(y)) fa[get_fa(x)] = get_fa(y);
        }
        for (int i=0; i<n ;i++) {
            if (get_fa(i) == i) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}