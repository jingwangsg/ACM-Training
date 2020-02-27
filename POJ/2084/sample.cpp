#include<iostream>
#include<cstring>
using namespace std;
typedef long long __int64;
const __int64 base=10000;
const int lenth=100;
void mul(__int64 a[],int len,int b)
{
    int i;
    __int64 jw=0;
    for(i=len-1;i>=0;i--)
    {
        jw=jw+a[i]*b;
        a[i]=jw%base;
        jw=jw/base;
    }
}
void div(__int64 a[],int len,int b)
{
    int i;
    __int64 jw=0;
    for(i=0;i<lenth;i++)
    {
        jw=jw*base+a[i];
        a[i]=jw/b;
        jw=jw%b;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
      int i,j,n;
      __int64 a[101][100];
      memset(a[1],0,sizeof(a[1]));
      a[1][lenth-1]=1;//a[1]初始化为1
      for(i=2;i<=100;i++)
      {
          memcpy(a[i],a[i-1],sizeof(a[1]));
          mul(a[i],lenth,4*i-2);
          div(a[i],lenth,i+1);
      }
      while(scanf("%d",&n)!=EOF)
      {
          if(n==-1)  break;
          for(i=0;i<lenth&&a[n][i]==0;i++);
                cout << a[n][i++];
              for(;i<lenth;i++)
                cout << a[n][i];
              printf("\n");  
      }
       
      return 0;
}
