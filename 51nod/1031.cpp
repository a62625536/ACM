#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
using namespace std;

int n;
long long dp[1005];

int main()
{
    scanf("%d",&n);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i <= n;i++)   dp[i] = (dp[i-1]+dp[i-2])%MOD;
    printf("%lld\n",dp[n]);
    return 0;
}
