#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100010;

bool visited[N];

struct PII {
    int first, second;
    void set_value(int l, int r) {
        this->first = l;
        this->second = r;
    }
};

struct SegTree {
    int ls, rs, col;
    int L, R;
}tree[N << 3]; int new_pnt;
int rt;

void pushdown(int p) {
    if (tree[p].col == -1) return;
    int ls = tree[p].ls, rs = tree[p].rs;
    if (ls != -1) tree[ls].col = tree[p].col;
    if (rs != -1) tree[rs].col = tree[p].col;
    tree[p].col = -1;
}

void build_tree(int &p, int l, int r) {
    p = new_pnt++;
    tree[p].col = -1;
    tree[p].ls = tree[p].rs = -1;
    tree[p].L = l;
    tree[p].R = r;

    if (r - l == 1) {
        return;
    }
    int mid = l + (r - l) / 2;
    build_tree(tree[p].ls, l, mid);
    build_tree(tree[p].rs, mid, r);
}

void cover(int p, int ll, int rr, int col) {
    int l = tree[p].L;
    int r = tree[p].R;
    if (ll <= l && r <= rr + 1) {
        tree[p].col = col;
        return;
    }
    pushdown(p);
    int mid = l + (r - l) / 2;
    if (ll < mid) cover(tree[p].ls, ll, rr, col);
    if (rr >= mid) cover(tree[p].rs, ll, rr, col);
}

void query(int p) {
    int l = tree[p].L;
    int r = tree[p].R;
    if (tree[p].col != -1) {
        // cout << l << " " << r << " " << tree[p].col << endl;
        visited[tree[p].col] = 1;
        return;
    }
    if (tree[p].ls == -1 && tree[p].rs == -1) {
        return;
    }
    int mid = l + (r - l) / 2;
    query(tree[p].ls);
    query(tree[p].rs);
}

int n; 
PII poster[N];
int uniq[N<<2];
int all[N<<1];
int cnt = 0;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    while (T--) {
        cin >> n;
        int l, r;
        cnt = 0;
        for (int i=0; i<n; i++) {
            cin >> l >> r;
            if (l > r) swap(l, r);
            poster[i].set_value(l, r);
            all[cnt++] = l;
            all[cnt++] = r;
        }
        sort(all, all + 2*n);
        uniq[0] = all[0];
        for (int i=1, cnt=1; i < 2*n; i++) {
            if (all[i] != uniq[cnt-1]) {
                if (all[i] - uniq[cnt-1] > 1) uniq[cnt++] = all[i] - 1;
                uniq[cnt++] = all[i];
            }
        }
        new_pnt = 0;
        rt = -1;
        build_tree(rt, 0, cnt);
        for (int i=0; i<n; i++) {
            int l = poster[i].first, r = poster[i].second;
            l = lower_bound(uniq, uniq+cnt, l) - uniq;
            r = lower_bound(uniq, uniq+cnt, r) - uniq;
            cover(rt, l, r, i+1);
        }
        memset(visited, 0, sizeof(visited));
        query(rt);
        int ans = 0;
        for (int i=1; i<=n; i++) if (visited[i]) ans ++;
        cout << ans << endl;
    }

    return 0;
}