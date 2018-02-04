#include<bits/stdc++.h>
using namespace std;

int n,m,a[505],dp[505][505],x[505][505];

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i = 1;i <= n;i++)   cin >> a[i];
        for(int i = 1;i <= n;i++)
        {
            int minn = 555;
            for(int j = i;j <= n;j++)
            {
                minn = min(minn,a[j]);
                x[i][j] = minn;
            }
        }
        memset(dp,0,sizeof(dp));
        for(int j = 1;j <= m;j++)
        {
            for(int i = n;i >= 1;i--)
            {
                for(int k = i;k >= 1;k--)   dp[i][j] = max(dp[i][j],dp[k-1][j-1]+(i-k+1)*x[k][i]);
            }
            for(int i = 1;i <= n;i++)   dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
