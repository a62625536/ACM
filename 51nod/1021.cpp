#include<bits/stdc++.h>
using namespace std;

int n,a[105],sum[105] = {0},dp[105][105];

int main()
{
    ios::sync_with_stdio(0);
    memset(dp,0x3f,sizeof(dp));
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)   sum[i] = sum[i-1]+a[i];
    for(int i = 1;i <= n;i++)   dp[i][i] = 0;
    for(int len = 2;len <= n;len++)
    {
        for(int l = 1;l+len-1 <= n;l++)
        {
            int r = l+len-1;
            for(int i = l;i < r;i++)    dp[l][r] = min(dp[l][r],dp[l][i]+dp[i+1][r]+sum[r]-sum[l-1]);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
