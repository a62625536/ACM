#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[1005][1005] = {0},n;

int main()
{
    dp[0][0] = 1;
    for(int i = 1;i <= 1000;i++)
    {
        dp[i][0] = 1;
        for(int j = 1;j < i;j++)    dp[i][j] = (dp[i-1][j]+dp[i][j-1])%10007;
        dp[i][i] = dp[i][i-1];
    }
    while(~scanf("%d",&n))  printf("%d\n",dp[n][n]);
    return 0;
}
