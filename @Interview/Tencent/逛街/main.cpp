#include<iostream>
#include<queue>
using namespace std;

const int N = 100010;

int n;
int v[N];
int see_left[N];
int see_right[N];

int main() {
    freopen("in.txt", "r", stdin);

    ios::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++) cin >> v[i];

    queue <int> left_q;
    queue <int> right_q;

    for (int i=0; i<n; i++) {
        //大于等于时算挡住，
        while (!left_q.empty() && left_q.front() <= v[i]) left_q.pop();
        left_q.push(v[i]);
        see_left[i] = left_q.size();
    }

    for (int i=n-1; i>=0; i--) {
        while (!right_q.empty() && right_q.front() <= v[i]) right_q.pop();
        right_q.push(v[i]);
        see_right[i] = right_q.size();
    }

    for (int i=0; i<n; i++) cout << see_right[i] << endl;

    cout << see_right[1] + 1 << " ";
    for (int i=1; i<n-1; i++) cout << see_right[i+1] + 1 + see_left[i-1] << " ";
    cout << see_left[n-2] + 1 << endl;
    return 0;
}