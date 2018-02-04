#include<bits/stdc++.h>
using namespace std;

int n,m,a[300005],vis[300005] = {0},dep[300005] = {0};
struct xxx
{
    int to,id;
    xxx(int a,int b):to(a),id(b){};
};
vector<xxx> v[300005];
vector<int> ans;

bool dfs(int now,int pre)
{
    vis[now] = 1;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i].to;
        if(t == pre || vis[t])    continue;
        if(dfs(t,now))
        {
            dep[now]++;
            ans.push_back(v[now][i].id);
        }
    }
    if(a[now] == 1 && dep[now]%2 == 0 || a[now] == 0 && dep[now]%2 == 1)    return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(xxx(y,i));
        v[y].push_back(xxx(x,i));
    }
    int ok = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == -1)
        {
            dfs(i,0);
            ok = 1;
            break;
        }
    }
    if(!ok && dfs(1,0))
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++)   cout << ans[i] << " ";
    cout << endl;
    return 0;
}
