#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010;

int n, m;
char cmap[N][N];
bool visited[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;

void dfs(int x, int y) {
    visited[x][y] = 1;
    // cout << x << "," << y << endl;
    for (int i=0; i<4; i++) {
        int next_x = x + dx[i], next_y = y + dy[i];
        if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) continue;
        if (visited[next_x][next_y] || cmap[next_x][next_y] == '#') continue;
        dfs(next_x, next_y);
    }
    ans ++;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*'.' - a black tile
    '#' - a red tile
    '@' - a man on a black tile(appears exactly once in a data set)
    */
    int stx, sty;

    while (cin >> n >> m && n && m) {
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin >> cmap[i][j];
                if (cmap[i][j] == '@') stx=i, sty=j;
            }
        }
        ans = 0;
        dfs(stx, sty);
        cout << ans << endl;
    }
    return 0;
}