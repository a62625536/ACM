#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
using namespace std;

long long dp[1005][1005] = {0};
int n,m;

int main()
{
	for(int i = 1;i <= 1000;i++)	dp[i][1] = 1;
	for(int i = 2;i <= 1000;i++)
	{
		for(int j = 2;j <= i;j++)	dp[i][j] = (dp[i-1][j-1]+dp[i-j][j])%MOD;
	}
	for(int i = 1;i <= 1000;i++)
	{
		for(int j = 1;j <= 1000;j++)	dp[i][j] = (dp[i][j-1]+dp[i][j])%MOD;
	}
	while(scanf("%d%d",&n,&m) && n && m)	printf("%lld\n",dp[n][m]);
	return 0;
}
