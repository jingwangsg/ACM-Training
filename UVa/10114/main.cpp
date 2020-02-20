#include<bits/stdc++.h>

using namespace std;

const int N = 101;

struct Loan {
    int month;
    float rate;
}dep_data[N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);

    int month, m, cnt, cur_month;
    double down, value, cur_rate, car_value, loan_value;

    while(cin >> month >> down >> value >> m && month > 0) {
        cur_month = 0;
        cnt = 0;
        car_value = loan_value = value;
        car_value += down;

        for (int i=0;i<m;i++) {
            cin >> dep_data[i].month >> dep_data[i].rate;
        }
        double monthpay = value / month;
        while (true) {
            if (dep_data[cnt].month == cur_month) {
                cur_rate = dep_data[cnt].rate;
                cnt ++;
            }
            car_value *= (1-cur_rate);
            if (car_value > loan_value) break;
            loan_value -= monthpay;
            cur_month ++;
        }
        if (cur_month == 1) 
            cout << "1 month\n";
        else cout << cur_month << " months\n";
    }
    
    

    return 0;
}