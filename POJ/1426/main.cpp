#include<iostream>
#include<cstring>
#include<queue>
#include<string>
using namespace std;

class node {
    public:
    node() {val = par = id = 0;}
    int val, par, id;
    int digit;
    node set_value(int val, int par, int digit, int id) {
        this->val = val;
        this->digit = digit;
        this->par = par;
        this->id = id;
        return *this;
    }
}q[100010]; int cnt=0;

node pushNode(int val, int par, int digit) {
    cnt ++;
    return q[cnt].set_value(val, par, digit, cnt);
}

bool accessed[210];
int n;
int ans_id;

void output_ans(int ans_id) {
    string ans = "";
    for(;ans_id != -1; ans_id = q[ans_id].par) {
        ans = (char)(q[ans_id].digit + '0') + ans;
    }
    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    while(cin >> n && n) {

        cnt = 0;
        int head = 1;
        memset(accessed, 0, sizeof(accessed));

        pushNode(1, -1, 1);
        while (head <= cnt) {
            node cur = q[head++];
            accessed[cur.val] = true;
            if (cur.val == 0) {
                ans_id = cur.id;
                break;
            }
            if (!accessed[(cur.val * 10) % n]) {
                pushNode((cur.val * 10) % n, cur.id, 0);
            }
            if (!accessed[(cur.val * 10 + 1) % n]) {
                pushNode((cur.val * 10 + 1) % n, cur.id, 1);
            }
        }

        output_ans(ans_id);
    }
    

    return 0;
}