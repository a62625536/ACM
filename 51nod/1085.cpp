#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,w[105],p[105],dp[10005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)   scanf("%d%d",&w[i],&p[i]);
    for(int i = 1;i <= n;i++)
    {
        for(int j = m;j >= w[i];j--)    dp[j] = max(dp[j],dp[j-w[i]]+p[i]);
    }
    printf("%d\n",dp[m]);
    return 0;
}
