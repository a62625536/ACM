#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1005][1005],x[1005],y[1005],n,m,k;

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i = 1;i <= n;i++)   x[i] = i;
        for(int i = 1;i <= m;i++)   y[i] = i;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)   scanf("%d",&a[i][j]);
        }
        int o,xx,yy;
        while(k--)
        {
            scanf("%d%d%d",&o,&xx,&yy);
            if(o == 0)  swap(x[xx],x[yy]);
            else    swap(y[xx],y[yy]);
        }
        for(int i = 1;i <= n;i++)
        {
            printf("%d",a[x[i]][y[1]]);
            for(int j = 2;j <= m;j++)   printf(" %d",a[x[i]][y[j]]);
            printf("\n");
        }
    }
    return 0;
}
