#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int src, tgt;

bool not_prime[10000];
int prime[10000], tot;
int q[100010], tail, head;
bool visited[10000];


void get_prime(int n) {
    not_prime[1] = true;
    for (int i=2; i<n; i++) {
        if (!not_prime[i]) prime[++tot] = i;
        for (int j=1; j<=tot; j++) {
            if (i * prime[j] >= n) break;
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

void pushNode(int x) {
    // printf("push[%d]: %d\n", tail, x);
    q[++tail] = x;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    int step;
    int ans = -1;
    get_prime(10000);
    cin >> T;
    while (T--) {
        memset(visited, 0, sizeof(visited));
        cin >> src >> tgt;
        head = 1;
        tail = 0;
        step = -1;
        ans = -1;
        pushNode(src);
        while (true) {
            int sz = tail - head + 1;
            step ++;
            if (!sz || ans != -1) break;
            while (sz--) {
                int cur = q[head++];
                visited[cur] = true;

                if (cur == tgt) {
                    ans = step;
                    break;
                }
                for (int mod=1; mod<=1000; mod*=10) {
                    for (int i=0; i<=9; i++) {
                        if (i == 0 && mod == 1000) continue;
                        int org_digit = ((cur / mod) - (cur / (mod * 10)) * 10);
                        int next = cur + (i - org_digit) * mod;
                        if (!not_prime[next] && !visited[next]) pushNode(next);
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}