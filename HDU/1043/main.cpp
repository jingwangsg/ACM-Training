#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int target_seq[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int target_state;
int init_seq[9];
int init_state;
int mov[4] = {-3, -1, 1, 3};
char mov_ch[4] = {'u', 'l', 'r', 'd'};
bool visited[400000];
int factorial[9];
int init_pos;
string ans;

int Cantor(int *seq);
void InvCantor(int state, int *seq);
int calc_h(int state);

struct SeqItem {
    SeqItem(){}
    SeqItem(int state_, int pos_, int g_, string path_) {
        this->state = state_;
        this->pos = pos_;
        this->g = g_;
        this->h = calc_h(state_);
        this->path = path_;
    }
    int state;
    //h - current cost, g - predicted cost
    int g, h;
    int pos;
    string path;
    bool operator <(const SeqItem &b)const {
        return g+h>b.g+b.h;
    }
};

priority_queue <SeqItem> q;

int Cantor(int *seq) {
    int cnt=0;
    int ret=0;
    for (int i=0; i<9; i++) {
        cnt = 0;
        for (int j=i+1; j<9; j++) if(seq[i] > seq[j]) cnt++;
        ret += factorial[8-i] * cnt;
    }
    return ret;
}

void InvCantor(int state, int *seq) {
    vector <int> rest_num;
    for (int i=0; i<9; i++) rest_num.push_back(i);
    for (int i=0; i<9; i++) {
        int rank_in_rest = state / factorial[8-i];
        state %= factorial[8-i];
        sort(rest_num.begin(), rest_num.end());
        seq[i] = rank_in_rest + 1;
    }
}

int calc_h(int state){
    int ret = 0;
    int seq[9];
    InvCantor(state, seq);
    for (int i=0; i<9; i++) {
        int r = i/3, c = i%3;
        int tr = (seq[i]-1)/3, tc = (seq[i]-1)%3;
        ret += abs(r - tr) + abs(c - tc);
    }
    return ret;
}

//number of inversion pairs is odd -> no solution
bool NoSolution() {
    int invs = 0;
    for (int i=0; i<9; i++) {
        for (int j=0; j<i; j++) {
            if (init_seq[i] < init_seq[j]) invs ++;
        }
    }
    return !(invs & 1);
}

void AStar() {
    while (!q.empty()) q.pop();
    q.push(SeqItem(init_state, init_pos, 0, ""));
    int cur_seq[9];
    while (!q.empty()) {
        SeqItem cur_item = q.top(); q.pop();
        int cur_state = cur_item.state;
        visited[cur_state] = 1;
        int cur_pos = cur_item.pos;
        int cur_g;
        InvCantor(cur_state, cur_seq);
        for (int i=0; i<4; i++) {
            int next_pos = cur_pos + mov[i];
            if (next_pos < 0 || next_pos > 8) continue;
            swap(cur_seq[cur_pos], cur_seq[next_pos]);
            int next_state = Cantor(cur_seq);
            swap(cur_seq[cur_pos], cur_seq[next_pos]);
            if (!visited[next_state]) {
                SeqItem next_item(next_state, next_pos, cur_item.g+1, cur_item.path+mov_ch[i]);
                if (next_state == target_state) {
                    ans = next_item.path;
                    return;
                }
                q.push(next_item);
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    int tmp = 1;
    factorial[0] = 1;
    for (int i=1; i<=8; i++) {
        tmp *= i;
        factorial[i] = tmp;
    }

    for (int i=0; i<9; i++) {
        char ch;
        cin >> ch;
        if (ch == 'x'){
            init_seq[i] = 9;
            init_pos = i;
        }
        else init_seq[i] = ch - '0';
    }

    target_state = Cantor(target_seq);
    if (!NoSolution()) {
        AStar();
        cout << ans;
    } else {
        cout << "unsolvable";
    }
    return 0;
}