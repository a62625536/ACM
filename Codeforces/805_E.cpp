#include<bits/stdc++.h>
using namespace std;

int n,m,cnt = 0,color[300005],a[300005];
vector<int> v[300005],s[300005];

void dfs(int now,int pre)
{
    map<int,int> mp;
    for(int i = 0;i < s[now].size();i++)
    {
        int t = s[now][i];
        if(color[t])    mp[color[t]] = 1;
    }
    int cntt = 0;
    for(int i = 0;i < s[now].size();i++)
    {
        int t = s[now][i];
        if(color[t])    continue;
        while(mp.count(++cntt));
        color[t] = cntt;
    }
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        dfs(t,now);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int ans = 1;
    for(int i = 1;i <= n;i++)
    {
        int x,y,now = 0;
        cin >> x;
        ans = max(x,ans);
        for(int j = 1;j <= x;j++)
        {
            cin >> y;
            s[i].push_back(y);
        }
    }
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    cout << ans << endl;
    for(int i = 1;i <= m;i++)
    {
        if(color[i] == 0)   cout << 1 << " ";
        else    cout << color[i] << " ";
    }
    cout << endl;
    return 0;
}
