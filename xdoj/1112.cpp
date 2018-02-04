#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define MOD 1000000007
using namespace std;

long long dp[1005][1005] = {0},ans[1005] = {0};
int n;

int main()
{
    dp[1][1] = 1;
    for(int i = 2;i <= 1000;i++)
    {
        for(int j = 1;j <= i;j++)   dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]*j)%MOD;
    }
    for(int i = 1;i <= 1000;i++)
    {
        for(int j = 1;j <= i;j++)   ans[i] = (ans[i]+dp[i][j])%MOD;
    }
    while(~scanf("%d",&n))  printf("%lld\n",ans[n]);
    return 0;
}
