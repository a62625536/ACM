#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
long long dp[1005][9005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    dp[0][0] = 1;
    for(int i = 0;i <= 9;i++)   dp[1][i] = 1;
    for(int i = 2;i <= n;i++)
    {
        for(int j = 0;j <= i*9;j++)
        {
            for(int k = 0;k <= 9;k++)
            {
                if(j >= k)  dp[i][j] = (dp[i][j]+dp[i-1][j-k])%MOD;
            }
        }
    }
    long long ans = 0;
    for(int i = 0;i <= n*9;i++) ans = (ans+dp[n][i]*(dp[n][i]-dp[n-1][i]+MOD))%MOD;
    cout << ans << endl;
    return 0;
}
