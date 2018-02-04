#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

LL n,x,y,z,t;
LL dp[105][105][105];

int main()
{
	while(~scanf("%d",&n))
	{
		scanf("%lld%lld%lld%lld",&x,&y,&z,&t);
		memset(dp,0,sizeof(dp));
		dp[1][0][0] = x*t;
		for(int i = 2;i <= n;i++)
		{
			for(int g = 0;g <= i;g++)
			{
				int b = 0;
				for(b = 0;b+g < i;b++)
				{
					int r = i-g-b;
					dp[i][g][b] = dp[i-1][g][b]+(g*y+x)*(b*z+t);
				}
				if(g > 0)	dp[i][g][b] = max(dp[i][g][b],dp[i-1][g-1][b]+y*(g-1)*(b*z+t));
				if(b > 0)	dp[i][g][b] = max(dp[i][g][b],dp[i-1][g][b-1]+g*y*((b-1)*z+t));
			}
		}
		LL ans = 0;
		printf("%lld\n",dp[2][1][1]);
		for(int i = 0;i <= n;i++)
		{
			for(int j = 0;j+i <= n;j++)	ans = max(ans,dp[n][i][j]);
		}
		printf("%lld\n",ans);
	}	
	return 0;
} 
