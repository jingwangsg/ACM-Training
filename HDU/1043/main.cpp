#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
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
int calc_h(int *seq);

struct SeqItem {
    SeqItem(){}
    SeqItem(int *seq_, int pos_, int g_, string path_) {
        for (int i=0; i<9; i++) this->seq[i] = seq_[i];
        this->pos = pos_;
        this->state = Cantor(this->seq);
        this->g = g_;
        this->h = calc_h(this->seq);
        this->path = path_;
    }
    int seq[9];
    int state;
    //h - current cost, g - predicted cost
    int g, h;
    int pos;
    string path;
    bool operator <(const SeqItem &b)const {
        return g+h>b.g+b.h;
    }
};



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

int calc_h(int *seq){
    int ret = 0;
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
        if (init_seq[i] == 9) continue;
        for (int j=0; j<i; j++) {
            if (init_seq[j] == 9) continue;
            if (init_seq[i] < init_seq[j]) invs ++;
        }
    }
    return invs&1;
}

void AStar() {
    priority_queue <SeqItem> q;
    memset(visited, 0, sizeof(visited));
    q.push(SeqItem(init_seq, init_pos, 0, ""));
    while (!q.empty()) {
        SeqItem cur_item = q.top(); q.pop();
        int cur_state = cur_item.state;
        visited[cur_state] = 1;
        int cur_pos = cur_item.pos;
        for (int i=0; i<4; i++) {
            int next_pos = cur_pos + mov[i];
            if (abs(mov[i]) == 1 && next_pos / 3 != cur_pos / 3) continue;
            if (next_pos < 0 || next_pos > 8) continue;
            swap(cur_item.seq[cur_pos], cur_item.seq[next_pos]);
            int next_state = Cantor(cur_item.seq);
            if (!visited[next_state]) {
                SeqItem next_item(cur_item.seq, next_pos, cur_item.g+1, cur_item.path+mov_ch[i]);
                if (next_state == target_state) {
                    ans = next_item.path;
                    return;
                }
                q.push(next_item);
            }
            swap(cur_item.seq[cur_pos], cur_item.seq[next_pos]);
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
    char ch;
    while (cin >> ch) {
        //read first char to make sure the input is not end
        if (ch == 'x'){
            init_seq[0] = 9;
            init_pos = 0;
        }
        else init_seq[0] = ch - '0';

        for (int i=1; i<9; i++) {
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
            cout << ans << endl;
        } else {
            cout << "unsolvable" << endl;
        }
    }
    return 0;
}