#include<iostream>
#include<cstring>
using namespace std;

const int N = 51;

int n;
int arr[2*N];
int ans[N]; int ans_cnt;
bool visited[N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<2*n; i++) cin >> arr[i];
        memset(visited, 0, sizeof(visited));

        int pnt = 2 * n - 1;

        ans_cnt = 0;

        for (int i=n-1; i>=0; i--) {
            while (pnt >= 0 && visited[pnt]) pnt--;
            visited[pnt] = true;
            for (int j=pnt-1; j>=0; j--) {
                if (arr[j] == arr[pnt]) {
                    visited[j] = true;
                    break;
                }
            }
            ans[ans_cnt++] = arr[pnt];
        }

        for (int i=n-1; i>=0; i--) cout << ans[i] << " ";
        cout << endl;
    }
}