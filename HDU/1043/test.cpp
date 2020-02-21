#include <iostream>
#include <cstring>
using namespace std;

void func(int *p) {
    for (int i=0; i<3; i++) p[i] = i;
}

int main() {
    int p[3];
    memset(p, 0, sizeof(p));
    func(p);
    for (int i=0; i<3; i++) cout << p[i] << " ";
    cout << endl;
}