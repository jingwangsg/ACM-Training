#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101;

int m, n;
//m - len, n - num

struct Unsort{
    int order;
    int unsort;
    string str;
    bool operator <(const Unsort &a)const {
        return this->unsort < a.unsort || (this->unsort == a.unsort && this->order < a.order);
    }
}arr[N];

void calc_unsort() {
    for (int i=0; i<n; i++) {
        int unsortedness = 0;
        string cur_str = arr[i].str;
        for (int j=0; j<m; j++) {
            for (int k=0; k<j; k++) {
                if (cur_str[j] < cur_str[k]) unsortedness++;
            }
        }
        arr[i].unsort = unsortedness;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    while (cin >> m >> n) {
        for (int i=0; i<n; i++) {
            cin >> arr[i].str;
            arr[i].order = i;
        }
        calc_unsort();
        sort(arr, arr+n);
        for (int i=0; i<n; i++) cout << arr[i].str << "\n";
    }
    return 0;
}