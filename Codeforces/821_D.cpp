#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n,m,k,x[10005],y[10005],vis[10005] = {0},dis[10005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    int s,t = 0;
    for(int i = 1;i <= k;i++)
    {
        cin >> x[i] >> y[i];
        if(x[i] == 1 && y[i] == 1)  s = i;
        if(x[i] == n && y[i] == m)  t = i;
    }
    if(!t)
    {
        t = ++k;
        x[k] = n+1;
        y[k] = m+1;
    }
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    for(int j = 1;j <= k;j++)
    {
        int pos = -1,minn = INF;
        for(int i = 1;i <= k;i++)
        {
            if(!vis[i] && dis[i] < minn)
            {
                pos = i;
                minn = dis[i];
            }
        }
        if(pos == -1)  break;
        vis[pos] = 1;
        for(int i = 1;i <= k;i++)
        {
            if(vis[i])  continue;
            if(abs(x[pos]-x[i])+abs(y[pos]-y[i]) == 1)  dis[i] = min(dis[i],dis[pos]);
            else if(abs(x[pos]-x[i]) <= 2 || abs(y[pos]-y[i]) <= 2) dis[i] = min(dis[i],dis[pos]+1);
        }
    }
    if(dis[t] == INF) cout << -1 << endl;
    else    cout << dis[t] << endl;
    return 0;
}
