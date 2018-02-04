#include<bits/stdc++.h>
using namespace std;

int n,m,dp[2][20] = {0};
string s[20];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        s[i] = " "+s[i];
    }
    int t;
    for(t = 1;t <= n;t++)
    {
        int flag = 0;
        for(int j = 1;j <= m+2;j++)
        {
            if(s[t][j] == '1')  flag = 1;
        }
        if(flag)    break;
    }
    if(t == n+1)
    {
        cout << 0 << endl;
        return 0;
    }
    dp[0][n+1] = -1;
    dp[1][n+1] = 1e9;
    for(int i = n;i >= t;i--)
    {
        int l = m+2;
        int r = 1;
        for(int j = m+2;j >= 1;j--)
        {
            if(s[i][j] == '1')  l = j;
        }
        for(int j = 1;j <= m+2;j++)
        {
            if(s[i][j] == '1')  r = j;
        }
        if(i == t)
        {
            cout << min(dp[0][i+1]+r,dp[1][i+1]+m+3-l) << endl;
            return 0;
        }
        dp[0][i] = min(dp[1][i+1]+m+2,dp[0][i+1]+2*(r-1)+1);
        dp[1][i] = min(dp[0][i+1]+m+2,dp[1][i+1]+2*(m+2-l)+1);
    }
    return 0;
}
