#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,k;
double a[1005],dp[1005][1005];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++)	scanf("%lf",&a[i]);
		dp[1][0] = 1-a[1];
		dp[1][1] = a[1];
		for(int i = 2;i <= n;i++)
		{
			for(int k = 0;k <= n;k++)
			{
				if(k == 0)	dp[i][k] = dp[i-1][k]*(1-a[i]);
				else		dp[i][k] = dp[i-1][k]*(1-a[i])+dp[i-1][k-1]*a[i];
			}
		}
		double ans = 0;
		for(int i = k;i <= n;i++)	ans += dp[n][i];
		printf("%.4f\n",ans);
	}
	return 0;
}
