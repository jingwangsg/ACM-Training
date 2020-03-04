#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

const int N = 100010;
const int INF = 0xfffffff;

ll n, s;
int v[N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    int min_len;
    int minx;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        minx = INF;
        min_len = INF;

        ll sum = 0;
        for (int i=1; i<=n; i++){
            cin >> v[i];
            sum += v[i];
        }
        if (sum < s) {
            cout << 0 << endl;
            continue;
        }
        int st, ed;
        st = ed = 1;
        ll cur_sum = v[1];
        //[st, ed]
        while (true) {
            while (ed <= n && cur_sum < s) {
                ed ++; 
                cur_sum += v[ed];
            }
            cur_sum -= v[st];
            min_len = min(min_len, ed - st + 1);
            if (ed == n+1) break;
            st ++;
        }
        cout << min_len << endl;
    }

    return 0;
}