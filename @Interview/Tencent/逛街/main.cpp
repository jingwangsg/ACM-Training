#include<iostream>
#include<stack>
using namespace std;

const int N = 100010;

int n;
int v[N];
int see_left[N];
int see_right[N];

int main() {

    ios::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++) cin >> v[i];

    stack <int> left_stk;
    stack <int> right_stk;

    for (int i=0; i<n; i++) {
        //大于等于时算挡住，
        while (!left_stk.empty() && left_stk.top() <= v[i]) left_stk.pop();
        left_stk.push(v[i]);
        see_left[i] = left_stk.size();
    }

    for (int i=n-1; i>=0; i--) {
        while (!right_stk.empty() && right_stk.top() <= v[i]) right_stk.pop();
        right_stk.push(v[i]);
        see_right[i] = right_stk.size();
    }


    cout << see_right[1] + 1 << " ";
    for (int i=1; i<n-1; i++) cout << see_right[i+1] + 1 + see_left[i-1] << " ";
    cout << see_left[n-2] + 1 << endl;
    return 0;
}