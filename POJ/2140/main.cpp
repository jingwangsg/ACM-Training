#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;

int prime[N/10];
int prime_exp[N/10];
int tot;
int ans;
bool not_prime[N];
int n;

int f[N];

void build_prime() {
    tot = 0;
    memset(not_prime, 0, sizeof(not_prime));
    for (int i=2; i<N; i++) {
        if (!not_prime[i]) prime[tot++] = i;
        for (int j=0; j<tot; j++) {
            if (i * prime[j] >= N) break;
            not_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void factorize(int n){
    int cnt = 0;
    memset(prime_exp, 0, sizeof(prime_exp));
    ans = 1;
    while(n != 1) {
        int prime_exp = 0;
        while (n % prime[cnt] == 0) {
            n /= prime[cnt];
            prime_exp++;
        }
        if (cnt) ans *= (prime_exp + 1);
        cnt++;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    build_prime();
    cin >> n;
    factorize(n * 2);
    cout << ans;
    return 0;
}