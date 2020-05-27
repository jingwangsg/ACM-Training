#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

class node {
    public:
    void set_value(int st, int ed) {
        this->st = st;
        this->ed = ed;
    }
    int st, ed;
}arr[110];
int n;

bool cmp(node a, node b) {
    return a.ed < b.ed;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n && n) {
        int st, ed;
        for (int i=0; i<n; i++) {
            cin >> st >> ed;
            arr[i].set_value(st, ed);
        }
        sort(arr, arr+n, cmp);
        int bound = 0;
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (arr[i].st < bound) continue;
            bound = arr[i].ed;
            ans ++;
        }
        cout << ans << endl;
    }
    

    return 0;
}