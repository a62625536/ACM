#include<bits/stdc++.h>
using namespace std;

int n,q,ans[1000005];
vector<int> v[1000005];

int dfs(int now,int pre)
{
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        ans[t] = min(t,ans[now]);
        dfs(t,now);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> q;
    int x,y;
    for(int i = 1;i < n;i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int lastt = 0;
    cin >> x >> y;
    y = (lastt+y)%n+1;
    ans[y] = y;
    dfs(y,-1);
    int minn = y;
    while(--q)
    {
        int x,y;
        cin >> x >> y;
        y = (y+lastt)%n+1;
        if(x == 1)  minn = min(minn,ans[y]);
        else
        {
            lastt = min(ans[y],minn);
            cout << lastt << endl;
        }
    }
    return 0;
}
