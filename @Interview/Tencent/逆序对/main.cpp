#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 21;
const int SIZE = 1 << MAXN;

ll arr[SIZE];
int n;
ll rev_cnt[MAXN];
ll max_cnt[MAXN];
ll sorted_arr[SIZE];

void mergesort(int index, int level) {
    //index - 第一个区间的开始下标
    if (level == 0) {
        sorted_arr[index] = arr[index];
        return;
    }
    int size = 1 << (level-1);
    vector <ll> ret(size * 2 + 1);
    ll st1 = index, st2 = index + size;
    ll ed1 = st2, ed2 = st2 + size;
    ll p1 = 0, p2 = 0;
    ll p = 0;
    mergesort(st1, level - 1);
    mergesort(st2, level - 1);
    while (st1 + p1 < ed1 && st2 + p2 < ed2) {
        if (sorted_arr[st1 + p1] == sorted_arr[st2 + p2]) {
            ll cnt1 = 1, cnt2 = 1;
            ret[p++] = sorted_arr[st1 + p1++];
            ret[p++] = sorted_arr[st2 + p2++];
            while (st1 + p1 < ed1 && sorted_arr[st1 + p1] == sorted_arr[st1 + p1 - 1]) {
                ret[p++] = sorted_arr[st1 + p1++];
                cnt1++;
            }
            rev_cnt[level] += cnt1 * (p2 - 1);
            while (st2 + p2 < ed2 && sorted_arr[st2 + p2] == sorted_arr[st2 + p2 - 1]) {
                ret[p++] = sorted_arr[st2 + p2++];
                cnt2++;
            }
            max_cnt[level] -= cnt1 * cnt2;
        }else if (sorted_arr[st1 + p1] > sorted_arr[st2 + p2]) {
            ret[p++] = sorted_arr[st2 + p2++];
        }else if (sorted_arr[st1 + p1] < sorted_arr[st2 + p2]) {
            ret[p++] = sorted_arr[st1 + p1++];
            rev_cnt[level] += p2;
        }
    }
    while (st1 + p1 < ed1) {
        ret[p++] = sorted_arr[st1 + p1++];
        rev_cnt[level] += p2;
    }
    while (st2 + p2 < ed2) ret[p++] = sorted_arr[st2 + p2++];
    for (int i=0; i<size*2; i++) sorted_arr[st1+i] = ret[i];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    #endif
    memset(rev_cnt, 0, sizeof(rev_cnt));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int size = 1 << n;
    for (ll i=0; i<size; i++) {
        cin >> arr[i];
    }

    for (ll i=1; i<=n; i++) {
        max_cnt[i] = 1ll << (n + i - 2);
    }

    mergesort(0, n);
    
    ll m;
    cin >> m;

    while (m--) {
        int level;
        ll sum = 0;
        cin >> level;
        for (ll i=1; i<=n; i++) {
            if (i <= level) rev_cnt[i] = max_cnt[i] - rev_cnt[i];
            sum += rev_cnt[i];
        }
        cout << sum << endl;
    }

    return 0;
}