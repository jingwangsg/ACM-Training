
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi acos(-1)
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int ncase,n;
    float R,r;
    while(scanf("%d",&ncase)!=EOF)
    {
        int count=0;
        while(ncase--)
        {
            scanf("%f%d",&R,&n);
            r=(R*sin(pi/n))/(1+sin(pi/n));
            printf("Scenario #%d:\n",++count);
            printf("%.3f\n\n",r);
        }
    }
    return 0;
}