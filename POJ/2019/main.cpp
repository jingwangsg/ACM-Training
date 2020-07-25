#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 251;

int n, b, T;
int min_rmq[N][N][8][8];
int max_rmq[N][N][8][8];

void init_rmq() {
    for (int i=1; (1 << i) < b; i++) {
        for (int j=1; (1 << j) < b; j++) {
            for (int k = 0; k < n - (1<<i) + 1; k++) {
                for (int l = 0; l < n - (1<<j) + 1; l++) {
                    min_rmq[k][l][i][j] = min(min(min_rmq[k][l][i-1][j-1],min_rmq[k][l+(1 << (j-1))][i-1][j-1]), min(min_rmq[k+(1 << (i-1))][l][i-1][j-1], min_rmq[k + (1 << (i-1))][l + (1 << (j-1))][i-1][j-1]));
                    max_rmq[k][l][i][j] = max(max(max_rmq[k][l][i-1][j-1],max_rmq[k][l+(1 << (j-1))][i-1][j-1]), max(max_rmq[k+(1 << (i-1))][l][i-1][j-1], max_rmq[k + (1 << (i-1))][l + (1 << (j-1))][i-1][j-1]));
                }
            }
        }
    }
}

int calc_rmq(int row1, int row2, int col1, int col2) {
    int len_row = row2 - row1, len_col = col2 - col1;
    int log_len_row = log2(len_row), log_len_col = log2(len_col);
    int min_val = min(min(min_rmq[row1][col1][log_len_row][log_len_col], min_rmq[row1][col2-(1<<log_len_col)][log_len_row][log_len_col]), min(min_rmq[row2-(1<<log_len_row)][col1][log_len_row][log_len_col], min_rmq[row2-(1<<log_len_row)][col2-(1<<log_len_col)][log_len_row][log_len_col]));
    int max_val = max(max(max_rmq[row1][col1][log_len_row][log_len_col], max_rmq[row1][col2-(1<<log_len_col)][log_len_row][log_len_col]), max(max_rmq[row2-(1<<log_len_row)][col1][log_len_row][log_len_col], max_rmq[row2-(1<<log_len_row)][col2-(1<<log_len_col)][log_len_row][log_len_col]));
    return max_val - min_val;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> b >> T;
    int tmp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> tmp;
            max_rmq[i][j][0][0] = min_rmq[i][j][0][0] = tmp;
        }
    }
    init_rmq();
    while (T--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int ans = calc_rmq(x, x+b, y, y+b);
        cout << ans << endl;
    }

    return 0;
}