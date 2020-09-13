#include<iostream>
using namespace std;

const int N = 200010;
const int INF = 0xffffff;

int arr[N];
int n;

bool check(int st) {
    int i = st, j = n - 1;
    int last = -INF;
    int cur_val;
    while (i <= j) {
        if (arr[i] > arr[j]) cur_val = arr[j], j--;
        else cur_val = arr[i], i++;
        if (cur_val < last) return false;
        else last = cur_val;
    }
    return true;
}

int search(int L, int R) {
    int l = L, r = R;
    while (l < r) {
        int mid = l + (r - l) / 2;
        bool res = check(mid);
        if (res) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> arr[i];
        int ans = search(0, n);
        cout << ans << endl;
    }
}