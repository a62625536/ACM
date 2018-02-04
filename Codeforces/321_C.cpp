#include<bits/stdc++.h>
using namespace std;

int n,k,root,son[100005],vis[100005] = {0},minn,sum,ok = 1;
char ans[100005];
vector<int> v[100005];

void dfsroot(int now,int pre)
{
    son[now] = 1;
    int maxx = 0;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre || vis[t])  continue;
        dfsroot(t,now);
        son[now] += son[t];
        maxx = max(maxx,son[t]);
    }
    maxx = max(maxx,sum-son[now]);
    if(maxx < minn)
    {
        minn = maxx;
        root = now;
    }
}

void solve(int now,char c)
{
    if(c > 'Z')
    {
        ok = 0;
        return;
    }
    ans[now] = c;
    vis[now] = 1;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(vis[t])  continue;
        minn = 1e9;
        sum = son[t];
        dfsroot(t,0);
        solve(root,c+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sum = n;
    minn = 1e9;
    dfsroot(1,0);
    solve(root,'A');
    if(!ok) cout << "Impossible!" << endl;
    else
    {
        for(int i = 1;i <= n;i++)   cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
