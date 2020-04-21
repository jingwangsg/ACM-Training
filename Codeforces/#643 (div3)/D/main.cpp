#include<iostream>
using namespace std;

int a[10][10];
char ch;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while(T--) {
        for (int i=0; i<9; i++) for (int j=0; j<9; j++) cin >> ch, a[i][j] = ch - '0';
        //row: k*3 + i   col: i * 3 + k
        for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
            a[j*3+i][i*3+j] = a[j*3+i][i*3+j]%9 + 1; 
        }
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}