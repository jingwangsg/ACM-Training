#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 110;
const int BASE = 10000;

struct BigInt {
    BigInt() {
        memset(this->d, 0, sizeof(this->d));
        this->sz = 1;
    }
    void set_small_value(int x) {
        this->d[0] = x;
    }

    BigInt& operator=(const BigInt &a) {
        memset(this->d, 0, sizeof(this->d));
        for (int i=0; i<a.sz; i++) this->d[i] = a.d[i];
        this->sz = a.sz;
        return *this;
    }

    friend BigInt operator+(const BigInt &a, const BigInt &b) {
        BigInt c;
        int maxlen = max(a.sz, b.sz);
        c.sz = maxlen;
        for (int i=0; i<maxlen; i++) {
            c.d[i] += a.d[i] + b.d[i];
            if (c.d[i] >= BASE) {
                c.d[i] -= BASE;
                c.d[i+1] ++;
                if (i+2 > maxlen) c.sz = i+2;
            }
        }
        return c;
    }

    friend BigInt operator*(const BigInt &a, const BigInt &b) {
        BigInt c;
        for (int i=0; i<a.sz; i++) {
            for (int j=0; j<b.sz; j++) {
                c.d[i+j] += a.d[i] * b.d[j];
                int cnt = i+j;
                while (c.d[cnt] >= BASE) {
                    c.d[cnt+1] += c.d[cnt] / BASE;
                    c.d[cnt] %= BASE;
                    cnt ++;
                }
            }
        }
        for (c.sz=1; c.d[c.sz]; c.sz++);
        return c;
    }

    void output() {
        printf("%d", this->d[this->sz - 1]);
        for (int i=this->sz - 2; i>=0; i--) printf("%04d", this->d[i]);
        cout << endl;
    }

    int d[110];
    int sz;
}f[N];

bool notAccessed(BigInt x) {
    return (x.d[0]==0 && x.sz==1);
}

BigInt calc_f(int n) {

    if (!notAccessed(f[n])) return f[n];
    BigInt ret;
    for (int i=2; i<=2*n; i+=2) {
        ret = ret + calc_f((i-2)/2) * calc_f((2*n - i)/2);
    }
    f[n] = ret;
    return ret;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    f[1].set_small_value(1);
    f[0].set_small_value(1);
    while (cin >> n && n != -1) calc_f(n).output();

    return 0;
}