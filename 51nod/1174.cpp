#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int n,q,a[10005],dp[10005][20];

void rmq_init()
{
    for(int i = 0;i < n;i++)    dp[i][0] = a[i];
    for(int j = 1;(1<<j) <= n;j++)
    {
        for(int i = 0;i+(1<<j)-1 < n;i++)
        {
            dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq(int l,int r)
{
    int k = (int)(log((double)(r-l+1))/log(2.0));
    return max(dp[l][k],dp[r-(1<<k)+1][k]);
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)    scanf("%d",&a[i]);
    rmq_init();
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",rmq(l,r));
    }
    return 0;
}
