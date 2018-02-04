#include<bits/stdc++.h>
using namespace std;

int n,m;
int hashh[300005],pre[300005],ans[300005] = {0},vis[300005] = {0},visc[600005] = {0};
vector <int> v[300005];

void dfs(int now)
{
    vis[now] = true;
    if(ans[now] == 0)   return;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(hashh[t] == hashh[now])  ans[t] = ans[now];
    }
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(vis[t])    continue;
        if(!ans[t])
        {
            if(!visc[ans[now]-1])
            {
                visc[ans[now]-1] = 1;
                ans[t] = ans[now]-1;
            }
            else if(!visc[ans[now]+1])
            {
                visc[ans[now]+1] = 1;
                ans[t] = ans[now]+1;
            }
        }
        dfs(t);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    pre[0] = 0;
    for(int i = 1;i <= n;i++)   pre[i] = pre[i-1]*31+i;
    for(int i = 1;i <= n;i++)   hashh[i] = pre[i];
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        hashh[x] += pre[y];
        hashh[y] += pre[x];
    }
    ans[1] = 300000;
    visc[300000] = 1;
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(!ans[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 1;i <= n;i++)   cout << ans[i] << " ";
    cout << endl;
    return 0;
}
