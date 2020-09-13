
#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int H = 32010;
const int N = 15010;

struct Star {
    int x, y;
    int idx;
    void setValue(int x, int y, int idx) {
        this->x = x;
        this->y = y;
        this->idx = idx;
    }
}stars[N];

int n;
int sum[H];
int ans[N];

bool cmp(Star a, Star b) {
    return (a.x == b.x) ? a.y < b.y : a.x < b.x;
}

int lowbit(int x) {return x & (-x);}

void add(int pos, int maxH, int val) {
    for (;pos <= maxH; pos += lowbit(pos)) sum[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (;pos >= 1; pos -= lowbit(pos)) ret += sum[pos];
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(sum, 0, sizeof(sum));

    while (cin >> n) {
        int x, y;
        int maxH = 0;
        for (int i=0; i<n; i++) {
            cin >> y >> x;
            y++;
            stars[i].setValue(x, y, i);
            maxH = max(maxH, y);
        }

        for (int i=0; i<n; i++) {
            ans[query(stars[i].y)] ++;
            add(stars[i].y, maxH, 1);
        }

        for (int i=0; i<n; i++) cout << ans[i] << "\n";
    }

    return 0;
}