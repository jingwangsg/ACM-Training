#include<iostream>
using namespace std;

const int NM = 50 * 50 + 10;

int fa[NM];
int con_map[NM];
int m, n;

int get_fa(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = get_fa(fa[x]);
}

bool valid(int x) {
    return x >= 0 && x < m * n;
}

int idx(int x, int y) {
    return x * n + y;
}

void join(int x, int y) {
    if (get_fa(x) != get_fa(y)) fa[get_fa(x)] = get_fa(y);
}

int con_bit(char ch) {
    //上右下左
    switch(ch)
    {
        case 'A':return 9;
        case 'B':return 12;
        case 'C':return 3;
        case 'D':return 6;
        case 'E':return 10;
        case 'F':return 5;
        case 'G':return 13;
        case 'H':return 11;
        case 'I':return 7;
        case 'J':return 14;
        case 'K':return 15;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    char ch;
    while (cin >> m >> n && m>0 && n>0) {
        for (int i=0; i<m*n; i++) fa[i] = i;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin >> ch;
                con_map[idx(i, j)] = con_bit(ch);
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int con = con_map[idx(i, j)];
                //上右下左
                int cur_idx = idx(i, j);
                int target_idx;

                target_idx = idx(i, j+1);
                if (j < n-1 && (con & 4) && (con_map[target_idx] & 1)) {
                    //con 左 target_con 右
                    join(cur_idx, target_idx);
                }
                target_idx = idx(i-1, j);
                if (i >= 1 && (con & 8) && (con_map[target_idx] & 2)) {
                    //con 上 target_con 下
                    join(cur_idx, target_idx);
                }
            }
        }
 
        int cnt = 0;
        for (int i=0; i<m*n; i++) {
            // cout << fa[i] << " ";
            // get_fa(i);
            if (fa[i] == i) cnt++;
        }
        // cout << endl;
        cout << cnt << endl;
    }
    
    return 0;
}