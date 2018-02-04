#include<bits/stdc++.h>
using namespace std;

int n,dp[1000005] = {0},prime[100000];
int main()
{
    ios::sync_with_stdio(false);
    int cnt = 0;
    for(int i = 2;i <= 1000000;i++)
    {
        if(dp[i])	continue;
        for(int j = 2*i;j <= 1000000;j += i)    dp[j] = 1;
    }
    for(int i = 2;i <= 1000000;i++)
    {
    	if(!dp[i])	prime[++cnt] = i;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1] = 0;
    for(int i = 1;i <= 1000000;i++)
    {
        dp[i+1] = min(dp[i]+1,dp[i+1]);
        for(int j = 1;j <= cnt;j++)
        {
        	long long k = (long long)i*prime[j];
        	if(k > 1000000)	break;
            dp[k] = min(dp[i]+1,dp[k]);
        }
    }
    while(cin >> n)  cout << dp[n] << endl;
    return 0;
}
