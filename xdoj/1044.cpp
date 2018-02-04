#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[15][15][15] = {0},a[3];

void init()
{
	for(int i = 9;i >= 1;i--)	dp[i][i][i] = dp[i+1][i+1][i+1]+1;
	dp[7][8][9] = 9;
	for(int i = 6;i >= 1;i--)	dp[i][i+1][i+2] = dp[i+1][i+2][i+3]+1;
	int x = 1,y = 2,z = 3;
	dp[1][2][3] -= 1;
	for(int i = 9;i >= 1;i--)
	{
		int j;
		for(j = 9;j > i;j--)
		{
			dp[i][i][j] = dp[x][y][z]+1;
			x = i;
			y = i;
			z = j;
		}
		for(j--;j >= 1;j--)
		{
			dp[j][i][i] = dp[x][y][z]+1;
			x = j;
			y = i;
			z = i;
		}
	}
	dp[1][2][3] += 1;
	dp[1][1][2] += 1;
	for(int k = 9;k >= 1;k--)
	{
		for(int j = k-1;j >= 1;j--)
		{
			for(int i = j-1;i >= 1;i--)
			{
				if(dp[i][j][k])	continue;
				dp[i][j][k] = dp[x][y][z]+1;
				x = i;
				y = j;
				z = k;
			}
		}
	}
	dp[1][1][2] -= 1;
	dp[2][3][5] += 9;
}

int main()
{
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		printf("%d\n",dp[a[0]][a[1]][a[2]]);
	}
	return 0;
}
