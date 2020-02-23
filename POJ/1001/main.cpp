#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 200;
const double eps = 1e-8;

struct BigInt {
    BigInt();
    BigInt(string str) {
        int len = str.length();
        this->sz = 0;
        memset(digit, 0, sizeof(digit));
        int accum = 0, cnt=1;
        for (int i=len-1; i>=0; i--) {
            int cur_digit = str[i] - '0';
            accum += cnt * cur_digit;
            cnt *= 10;
            if ((len-i)%4 == 0) {
                this->digit[this->sz++] = accum;
                accum = 0;
                cnt = 1;
            }
        }
        if (accum) {
            this->digit[this->sz++] = accum;
        }
    }

    BigInt& operator=(const BigInt &a) {
        this->sz = a.sz;
        memset(this->digit, 0, sizeof(this->digit));
        for (int i=0; i<this->sz; i++) this->digit[i] = a.digit[i];
        return *this;
    }

    friend BigInt operator*(const BigInt &a, const BigInt &b) {
        BigInt ret("0");
        ret.sz = 0;
        for (int i=0; i<a.sz; i++) {
            for (int j=0; j<b.sz; j++) {
                ret.digit[i+j] += a.digit[i] * b.digit[j];
                ret.sz = max(ret.sz, i+j);
                int pnt = i + j;
                while (ret.digit[pnt] > 10000) {
                    ret.digit[pnt+1] += ret.digit[pnt] / 10000;
                    ret.sz = max(ret.sz, pnt+1);
                    ret.digit[pnt] %= 10000;
                }
            }
        }
        ret.sz ++;
        return ret;
    }

    string to_str(){
        string str = "";
        for (int i=0; i<this->sz; i++) {
            int cur_digit = this->digit[i];
            for (int k=0; k<4; k++) {
                str = (char)(cur_digit % 10 + '0') + str;
                cur_digit /= 10;
            }
        }
        while (str[0] == '0') str.erase(str.begin());
        return str;
    }
    int digit[N];
    int sz;
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    double f;
    string str="";
    int pos, bias;
    int cnt=0;
    int n;

    while (cin >> f) {
        cin >> n;
        int bias = 0, mult_bias = 1;
        while (abs(f * mult_bias - floor(f*mult_bias)) > eps){
            bias++;
            mult_bias*=10;
        }
        int tmp = floor(f * mult_bias);
        if (tmp == 0) {
            cout << 0 << endl;
            continue;
        }
        string str = "";
        while(tmp) {
            str = (char)(tmp%10 + '0') + str;
            tmp /= 10;
        }
        if (n == 0) {
            cout << 1 << endl;
            continue;
        }
        BigInt a(str);
        BigInt res(str);
        for (int i=1; i<n; i++) {
            res = res * a;
        }
        int digit_after_dot = bias * n;
        string res_str = res.to_str();
        int len = res_str.length();
        if (len <= digit_after_dot) {
            cout << ".";
            while(digit_after_dot > len){
                digit_after_dot --;
                cout << "0";
            }
            cout << res_str << endl;
        } else {
            if (digit_after_dot) res_str.insert(len - digit_after_dot, ".");
            cout << res_str << endl;
        }

    }

    return 0;
}