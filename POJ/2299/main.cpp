#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 500010;
typedef long long ll;

int n;
int tot;
ll arr[N];
ll sum[N];
ll uniq[N];

int lowbit(int x) {return x & (-x);}

void add(int pos, ll v) {
    for (; pos < tot+2; pos += lowbit(pos)) {
        sum[pos] += v;
    }
}

ll count(int pos) {
    ll ret = 0;
    for (; pos > 0; pos -= lowbit(pos)) {
        ret += sum[pos];
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n && n) {
        memset(sum, 0, sizeof(sum));

        for (int i=0; i<n; i++) {
            cin >> arr[i];
            uniq[i] = arr[i];
        }
        sort(uniq, uniq+n);
        tot = 0;
        uniq[tot++] = uniq[0];
        for (int i=1; i<n; i++) if (uniq[tot-1] != uniq[i]) uniq[tot++] = uniq[i];
        for (int i=0; i<n; i++) {
            arr[i] = lower_bound(uniq, uniq+tot, arr[i]) - uniq + 2;
        }
        ll ans = 0;
        for (int i=n-1; i>=0; i--) {
            ans += count(arr[i]-1);
            add(arr[i], 1);
        }
        cout << ans << endl;
    }

    return 0;
}