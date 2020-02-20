#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 21;

int target;
int ans_cnt;

bool visited[N];
int path[N], path_pnt;
int connect[N][N];

void dfs(int p) {
    visited[p] = 1;
    path[path_pnt++] = p;
    bool all_visited = 0;
    if (p == target) {
        all_visited = 1;
        for (int i=1; i<=20; i++) {
            if (!visited[i]){
                all_visited = 0;
                break;
            }
        }
    }
    if (all_visited) {
        ans_cnt++;
        cout << ans_cnt <<":  "<<target;
        for (int j=0; j<20; j++) {
            cout << " "<< path[j];
        }
        cout << "\n";
    } else {
        for (int next_p=1; next_p<=20; next_p++)
        if (connect[p][next_p]){
            if (!visited[next_p]) dfs(next_p);
        }
    }
    visited[p] = 0;
    path_pnt --;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    memset(connect, 0, sizeof(connect));
    int p;
    int arr[3];
    for (int i=1; i<=20; i++) {
        for (int j=0; j<3; j++){
            cin >> p;
            connect[i][p] = 1;
        }
    }
    while (cin >> p && p) {
        target = p;
        ans_cnt = 0;
        path_pnt = 0;
        for (int next_p=1; next_p<=20; next_p++){
            if (connect[p][next_p]){
                dfs(next_p);
            }
        }
    }

    return 0;
}