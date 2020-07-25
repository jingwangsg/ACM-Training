#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;

const int MAXN = 25010;

int n, L;
vector<pair<int, int> > ver;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> L;
    int l, r;
    for (int i=0; i<n; i++) {
        cin >> l >> r;
        ver.push_back(make_pair(l, r));
    }
    sort(ver.begin(), ver.end());
    int t = 0, maxr = 0;
    int cnt = 0;
    int nextr;
    if (ver[0].first != 1) {
        cout << -1 << endl;
        exit(0);
    }
    while (t < n) {
        nextr = maxr;
        while (t < n && ver[t].first <= maxr + 1) {
            nextr = max(nextr, ver[t].second);
            t++;
        }
        if (maxr == nextr) break;
        maxr = nextr;
        cnt ++;
    }

    if (maxr >= L) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}