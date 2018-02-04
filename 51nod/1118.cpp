#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
using namespace std;

int n,m,dp[1005][1005] = {0};

int main()
{
    scanf("%d%d",&n,&m);
    dp[0][1] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;i <= m;j++)   dp[i][j] = (dp[i][j-1]+dp[i-1][j])%MOD;
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
