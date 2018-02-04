#include<bits/stdc++.h>
using namespace std;

int n,m,k,g[85][85],dp[85][85][85][85];

int dfs(int now,int l,int r,int cnt)
{
    int &ans = dp[now][l][r][cnt];
    if(ans != -1)    return ans;
    if(cnt == k)
    {
        ans = 0;
        return 0;
    }
    ans = 1e9;
    for(int i = l+1;i < r;i++)
    {
        if(g[now][i] == 1e9)  continue;
        int x = l,y = r;
        if(now < i) x = now;
        else    y = now;
        ans = min(ans,g[now][i]+dfs(i,x,y,cnt+1));
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   g[i][j] = 1e9;
    }
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i <= m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y],z);
    }
    int ans = 1e9;
    for(int i = 1;i <= n;i++)   ans = min(ans,dfs(i,0,n+1,1));
    if(ans == 1e9)  cout << -1 << endl;
    else    cout << ans << endl;
    return 0;
}
