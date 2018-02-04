#include<bits/stdc++.h>
using namespace std;

int n,p,l,a[1005] = {0},b[1005] = {0},dp[2][1005][55][55] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> p >> l;
    p = min((n+l-1)/l*2,p);
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        b[x] = 1;
    }
    int now = 0;
    memset(dp[now],0xcf,(p+1)*sizeof(dp[0][0]));
    dp[now][0][0][0]=0;
    for(int _ = 1;_ <= n;_++)
    {
        int la = now;
        now ^= 1;
        memset(dp[now],0xcf,(p+1)*sizeof(dp[0][0]));
        for(int i = 0;i <= p;i++)
        {
            for(int j = 0;j <= l;j++)
            {
                for(int k = 0;k <= l;k++)
                {
                    int tj = max(j-1,0),tk = max(k-1,0),ad = ((a[_] && tj) || (b[_] && tk));
                    dp[now][i][tj][tk] = max(dp[now][i][tj][tk],dp[la][i][j][k]+ad);
                    tj = l,tk = max(k-1,0),ad = (a[_] || (b[_] && tk));
                    dp[now][i+1][tj][tk] = max(dp[now][i+1][tj][tk],dp[la][i][j][k]+ad);
                    tj = max(j-1,0),tk = l,ad = ((a[_] && tj) || b[_]);
                    dp[now][i+1][tj][tk] = max(dp[now][i+1][tj][tk],dp[la][i][j][k]+ad);
                    tj = l,tk = l,ad = (a[_] || b[_]);
                    dp[now][i+2][tj][tk] = max(dp[now][i+2][tj][tk],dp[la][i][j][k]+ad);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= p;i++)
    {
        for(int j = 0;j <= l;j++)
        {
            for(int k = 0;k <= l;k++)   ans = max(ans,dp[now][i][j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}
