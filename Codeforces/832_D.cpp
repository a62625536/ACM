#include<bits/stdc++.h>
using namespace std;

int n,q,dep[100005] = {0},fa[100005][25];
vector<int> v[100005];

void dfs(int now,int pre)
{
    dep[now] = dep[pre]+1;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        fa[t][0] = now;
        dfs(t,now);
    }
}

int lca(int x,int y)
{
    if(dep[x] < dep[y]) swap(x,y);
    int t = dep[x]-dep[y];
    for(int i = 0;i <= 20;i++)
    {
        if((1<<i)&t)    x = fa[x][i];
    }
    if(x == y)  return x;
    for(int i = 20;i >= 0;i--)
    {
        if(fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int f(int x,int y,int z)
{
    int xy = lca(x,y),xz = lca(x,z),yz = lca(y,z);
    int ans = dep[x]-max(dep[xy],dep[xz])+1;
    if(xy == xz)    ans += dep[yz]-dep[xy];
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 2;i <= n;i++)
    {
        int x;
        cin >> x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
    dfs(1,0);
    for(int i = 1;i <= 20;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
    while(q--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        int ans1 = f(x,y,z);
        int ans2 = f(y,x,z);
        int ans3 = f(z,x,y);
        cout << max(ans1,max(ans2,ans3)) << endl;
    }
    return 0;
}
