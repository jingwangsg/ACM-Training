#include<iostream>
#include<algorithm>

using namespace std;

const int N = 8010;

int n, k[N];
int sum[N];
int res[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int pos, int v) {
    for(; pos < n; pos += lowbit(pos)) sum[pos] += v;
}

int count(int pos) {
    int ret = 0;
    for(; pos > 0; pos -= lowbit(pos)) ret += sum[pos];
    return ret;
}

int lower_bound(int v) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (count(mid) < v) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i++) add(i, 1);
    for (int i = 2; i <= n; i++) cin >> k[i];

    for (int i = n; i >= 1; i--) {
        int pos = lower_bound(k[i]+1);
        res[i] = pos;
        add(pos, -1);
    }

    for (int i = 1; i <= n; i++) cout << res[i] << endl;

    return 0;
}