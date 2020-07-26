#include<iostream>
using namespace std;

const int N = 1010;

int n, a[N], b[N], c[N];
int cnt = 0;

class TreeNode {
    public:
    TreeNode(int id) {
        this->id = id;
        ls = rs = NULL;
    }
    int id;
    TreeNode *ls, *rs;
};

TreeNode* rt;
void buildTree(int* a, int* b, int n, TreeNode *&rt) {
    rt = new TreeNode(a[0]);
    if (n == 1) return;
    int i;
    for (i=0; i<n; i++) {
        if (b[i] == a[0]) break;
    }
    if (i > 0) buildTree(a+1, b, i, rt->ls);
    if (n-1 > i) buildTree(a+i+1, b+i+1, n-(i+1), rt->rs);
}

void postOrder(TreeNode *rt) {
    if (rt->ls != NULL) postOrder(rt->ls);
    if (rt->rs != NULL) postOrder(rt->rs);
    c[cnt++] = rt->id;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        //preorder
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i ++ ) {
            cin >> b[i];
        }
        rt = NULL;
        cnt = 0;

        buildTree(a, b, n, rt);
        postOrder(rt);

        for (int i=0; i<n; i++) {
            cout << c[i];
            if (i == n-1) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}