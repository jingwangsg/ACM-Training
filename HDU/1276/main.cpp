#include <iostream>
#include <cstring>
using namespace std;

const int N = 5010;

int n;
struct LinkedList {
    int id;
    LinkedList* prev, *next;
}pool[N]; LinkedList* head;
int round[2] = {2, 3};

void del(LinkedList *p) {
    LinkedList *pNext = p->next, *pPrev = p->prev;
    if (pPrev != NULL) pPrev->next = pNext;
    if (pNext != NULL) pNext->prev = pPrev;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    int flag;

    while (T--) {
        cin >> n;
        int numOut = 0;
        flag = 0;

        head = pool;
        for (int i=0; i<n; i++) {
            pool[i].id = i+1;
            if (i > 0) pool[i].prev = pool + i - 1; else pool[i].prev = NULL;
            if (i < n-1) pool[i].next = pool + i + 1; else pool[i].next = NULL;
        }

        int t;

        while (numOut < n-3) {
            t = 0;
            for (LinkedList *p = head; p != NULL; p = p->next) {
                t++;
                if (t == round[flag]) {
                    del(p);
                    numOut++;
                    t = 0;
                }
            }
            flag ^= 1;
        }

        for (LinkedList *p = head; p != NULL; p = p->next) {
            cout << p->id;
            if (p->next != NULL) cout << " ";
            else cout << "\n";
        }
    }

    return 0;
}