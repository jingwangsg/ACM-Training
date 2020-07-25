#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 10010;
const int logN = 15;

vector <int>::iterator it[N];
vector <int> G[N];

int fa[N][logN];
int depth[N], ind[N];
int n, rt;

void dfs(int p, int f) {
    depth[p] = 0 ? f == -1 : depth[f] + 1;
    fa[p][0] = fa;
    int sz = fa[p].size();
    for (int i=0; i<sz; i++) {
        if (G[p][i] != f) {
            dfs(G[p][i], p);
        }
    }
}

void build_table() {
    dfs(rt, -1);
    for (int level=0; level+1 < logN; level++) {
        for (int i=1; i<=n; i++) {
            if (fa[i][level] < 0) fa[i][level+1] = -1;
            else fa[i][level+1] = fa[fa[i][level]][level];
        }
    }
}



int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    char opt[10];
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        memset(ind, 0, sizeof(ind));
        for (int i=1; i<=n; i++) G[i].clear();

        int x, y;
        for (int i=0; i<n-1; i++) {
            cin >> x >> y;
            G[x].push_back(x);
            G[y].push_back(y);
        }
        while (scanf("%s", opt)) {
            if (opt[0] == 'D') break;
            cin >> x >> y;
            if (opt[0] == 'C') {
                *it[x] = y;
            }
            if (opt[0] == 'N') {

            }
        }
    }

    return 0;
}