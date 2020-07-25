#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 10010;
const int logN = 15;

vector <int> G[N];
int rt, T, n;
int ind[N];
int fa[N][logN];
int depth[N];

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

void dfs(int p, int f) {
    int sz = G[p].size();
    depth[p] = 0 ? f == -1 : depth[f] + 1;
    fa[p][0] = f;
    for (int i=0; i<sz; i++) {
        if (G[p][i] != f) dfs(G[p][i], p);
    }
}

void build_table() {
    for (int level=0; level+1<logN; level++) {
        for (int i=1; i<=n; i++) {
            if (fa[i][level] < 0) fa[i][level+1] = -1;
            else fa[i][level + 1] = fa[fa[i][level]][level];
        }
    }
}

int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int delta = depth[v] - depth[u];
    for (int i=0; i<logN; i++) {
        if ((delta >> i) & 1) {
            v = fa[v][i];
        }
    }
    if (u == v) return u;
    int level = logN-1;
    while (fa[u][0] != fa[v][0]) {
        while (fa[u][level] == fa[v][level]) level --;
        u = fa[u][level];
        v = fa[v][level];
    }
    return fa[u][0];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> T;
    while(T--) {
        memset(ind, 0, sizeof(ind));
        cin >> n;
        for (int i=1; i<=n; i++) G[i].clear();

        int u, v;
        for (int i=0; i<n-1; i++) {
            cin >> u >> v;
            add_edge(u, v);
            ind[v]++;
        }
        for (int i=1; i<=n; i++) {
            if (ind[i] == 0) {
                rt = i;
                break;
            }
        }
        dfs(rt, -1);
        build_table();

        cin >> u >> v;
        int ans = query(u, v);
        cout << ans << endl;
    }
}