#include<bits/stdc++.h>
using namespace std;

int n,m,has[1000005] = {0},deg[1000005] = {0},vis[1000005] = {0};
vector<int> v[1000005];

void dfs(int now)
{
    if(vis[now])    return;
    vis[now] = 1;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(vis[t])  continue;
        dfs(t);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int cnt = 0;
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        cin >> x >> y;
        has[x] = 1;
        has[y] = 1;
        v[x].push_back(y);
        v[y].push_back(x);
        if(x == y)  cnt++;
        else
        {
            deg[x]++;
            deg[y]++;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(has[i])
        {
            dfs(i);
            break;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(has[i] && !vis[i])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    long long ans = (long long)cnt*(cnt-1)/2+(long long)cnt*(m-cnt);
    for(int i = 1;i <= n;i++)
    {
        if(has[i])  ans += (long long)deg[i]*(deg[i]-1)/2;
    }
    cout << ans << endl;
    return 0;
}
