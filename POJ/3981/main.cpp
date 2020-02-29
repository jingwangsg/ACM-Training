#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char str[1010];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    while(~scanf("%s", str)) {
        int len = strlen(str);
        for (int i=0; i<len-2; i++) {
            printf("%d#%c\n", i, str[i]);
            if (str[i] == 'y' && str[i+1] == 'o' && str[i+2] == 'u'){
                printf("we");
                i += 2;
            }
            else printf("%c", str[i]);
        }
        printf("%c%c",str[len-2], str[len-1]);
    }

    return 0;
}