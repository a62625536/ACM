#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,m,a[5005],b[5005],sz[5005] = {0},ok[5005] = {0};
long long dp[5005][5005][2];
vector<int> v[5005];

void dfs(int now)
{
    if(ok[now]) return;
    dp[now][0][0] = 0;
    dp[now][1][0] = a[now];
    dp[now][1][1] = b[now];
    sz[now] = 1;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        dfs(t);
        for(int i = sz[now];i >= 0;i--)
        {
            for(int j = sz[t];j >= 0;j--)
            {
                dp[now][i+j][0] = min(dp[now][i+j][0],dp[now][i][0]+dp[t][j][0]);
                dp[now][i+j][1] = min(dp[now][i+j][1],dp[now][i][1]+min(dp[t][j][0],dp[t][j][1]));
            }
        }
        sz[now] += sz[t];
    }
    ok[now] = 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> b[i];
        b[i] = a[i]-b[i];
        if(i > 1)
        {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dfs(1);
    for(int i = n;i >= 0;i--)
    {
        if(dp[1][i][0] <= m || dp[1][i][1] <= m)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
