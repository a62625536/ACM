#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,a[1005][1005],x[1005] = {0},y[1005] = {0};

int main()
{
    int ans = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            scanf("%d",&a[i][j]);
            if(x[i] && !a[i][j])    ans++;
            else if(!x[i] && a[i][j])   x[i] = 1;
            if(y[j] && !a[i][j])    ans++;
            else if(!y[j] && a[i][j])   y[j] = 1;
        }
    }
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    for(int i = n;i >= 1;i--)
    {
        for(int j = m;j >= 1;j--)
        {
            if(x[i] && !a[i][j])   ans++;
            else if(!x[i] && a[i][j])   x[i] = 1;
            if(y[j] && !a[i][j])    ans++;
            else if(!y[j] && a[i][j])   y[j] = 1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
