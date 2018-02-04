#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long dp[75];

int main()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4;i <= 70;i++)	dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	int n;
	while(~scanf("%d",&n))	printf("%lld\n",dp[n]);
	return 0;
}
