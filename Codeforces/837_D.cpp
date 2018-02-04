#include<bits/stdc++.h>
using namespace std;

int n,k,cnt1[205] = {0},cnt2[205] = {0},dp[205][6005];
long long a[205];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        while(a[i]%2 == 0)
        {
            a[i] /= 2;
            cnt2[i]++;
        }
        while(a[i]%5 == 0)
        {
            a[i] /= 5;
            cnt1[i]++;
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = k;j >= 1;j--)
        {
            for(int t = 6000;t >= cnt1[i];t--)
            {
                if(dp[j-1][t-cnt1[i]] != -1)    dp[j][t] = max(dp[j][t],dp[j-1][t-cnt1[i]]+cnt2[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= 6000;i++)    ans = max(ans,min(i,dp[k][i]));
    cout << ans << endl;
    return 0;
}
