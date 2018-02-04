#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

double p[25],dp[25][25];
int n,k;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++)	scanf("%lf",&p[i]);
		dp[0][0] = 1;
		for(int i = 1;i <= n;i++)
		{
			dp[i][0] = dp[i-1][0]*(1-p[i]);
			dp[i][i] = dp[i-1][i-1]*p[i];
			for(int j = 0;j < n;j++)	dp[i][j] = dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);	
		}
		double x = 0;
		for(int i = k;i <= n;i++)	x += dp[n][i];
		printf("%.1f\n",x/(1-x));
	}
	return 0;
}
