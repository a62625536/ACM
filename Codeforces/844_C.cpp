#include<bits/stdc++.h>
using namespace std;

int n,a[100005],b[100005],cnt,vis[100005] = {0};
vector<int> v[100005],ans[100005];
map<int,int> mp;

void dfs(int x)
{
    vis[x] = 1;
    ans[cnt].push_back(x);
    for(int i = 0;i < v[x].size();i++)
    {
        int t = v[x][i];
        if(vis[t])  continue;
        dfs(t);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i],b[i] = a[i];
    sort(b+1,b+1+n);
    for(int i = 1;i <= n;i++)   mp[b[i]] = i;
    for(int i = 1;i <= n;i++)   v[i].push_back(mp[a[i]]);
    cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
    for(int i = 1;i <= cnt;i++) sort(ans[i].begin(),ans[i].end());
    for(int i = 1;i <= cnt;i++)
    {
        cout << ans[i].size() << " ";
        for(int j = 0;j < ans[i].size();j++)    cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
