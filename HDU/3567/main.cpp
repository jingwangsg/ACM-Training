#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
//! https://www.geeksforgeeks.org/bidirectional-search/?ref=lbp

char ch;
int A[9], B[9];
int dx[4] = {3, -1, 1, -3};
char opt[4] = {'d', 'l', 'r', 'u'};
int fact[9];
int tmp_arr[9];
int tgt_hash;
int case_id;
bool visited[370000];
//keep track of the transition betweeen states and parent nodes
struct list {
    int opt, parent_p, len;
}


struct QueItem {
    int state[9];
    int hash;
    int pos;
    string opts;

    QueItem(int *state_) {
        for (int i=0; i<9; i++){ 
            this->state[i] = state_[i];
            if (this->state[i] == 0) pos = i;
        }
        this->get_hash();
        this->opts = "";
    }

    QueItem& operator =(const QueItem &node_) {
        for (int i=0; i<9; i++) this->state[i] = node_.state[i];
        this->hash = node_.hash;
        this->pos = node_.pos;
        return *this;
    }

    void get_hash() {
        int cnt;
        this->hash = 0;
        for (int i=0; i<9; i++) {
            cnt = 0;
            for (int j=i+1; j<9; j++) {
                if (this->state[i] > this->state[j]) cnt++;
            }
            this->hash += cnt * fact[8-i];
        }
    }
};
queue <QueItem> q;

//! https://www.geeksforgeeks.org/bidirectional-search/
void bfs(queue <QueItem> q, bool *visited, int *parent, bool direction) {
    QueItem cur_node = q.front(); q.pop();
    if (direction) {
        //forward
        for (int i=0; i<4; i++) {
            //check if the opt is valid
            int cur_pos = cur_node.pos;
            

        }
    }
}

void bfs() {
    while (!q.empty()) {
        QueItem cur_node = q.front(); q.pop();
        visited[cur_node.hash] = 1;
        for (int i=0; i<4; i++) {
            int cur_pos = cur_node.pos;
            int next_pos = cur_pos + dx[i];
            if (next_pos < 0 || next_pos >= 9) continue;
            //not in the same row
            if (abs(dx[i]) == 1 && (int)(cur_pos / 3) != (int)(next_pos / 3)) continue;
            //if valid, check if it's visited

            for (int i=0; i<9; i++) tmp_arr[i] = cur_node.state[i];
            swap(tmp_arr[cur_pos], tmp_arr[next_pos]);

            QueItem new_node = node(tmp_arr);
            new_node.opts = cur_node.opts + opt[i];
            if (!visited[new_node.hash]) q.push(new_node);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    //preprocess the factorial
    fact[0] = 1;
    fact[1] = 1;
    for (int i=2;i<=9;i++) fact[i] = fact[i-1] * i;

    int T;
    cin >> T;
    while (T--) {
        case_id++;
        q = queue <node> ();
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<9; i++) {
            cin >> ch;
            if (ch == 'X') A[i] = 0; else A[i] = ch - '0';
        }
        for (int i=0; i<9; i++) {
            cin >> ch;
            if (ch == 'X') B[i] = 0; else B[i] = ch - '0';
        }
        node st(A),tgt(B);
        tgt_hash = tgt.hash;
        q.push(st);
        bfs();
    }

    return 0;
}