#include<bits/stdc++.h>
using namespace std;

int n,x,a[200005] = {0},maxx[200005],ok[200005] = {0};
int ans;
vector<int> v[200005];

void dfs1(int now,int pre)
{
    maxx[now] = a[now];
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        a[t] = a[now]+1;
        dfs1(t,now);
        if(ok[t])   ok[now] = 1;
        maxx[now] = max(maxx[now],maxx[t]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> x;
    ok[x] = 1;
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(1,-1);
    ans = maxx[x];
    for(int i = 2;i <= n;i++)
    {
        if(ok[i])
        {
            if(a[x]-a[i] < a[i])    ans = max(ans,maxx[i]);
        }
    }
    cout << ans*2 << endl;
    return 0;
}
