#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[1005][1005],vis[1005],cost[1005],n,m;

int prim()
{
    int ans = 0;
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    for(int i = 2;i <= n;i++)   cost[i] = a[1][i];
    for(int i = 2;i <= n;i++)
    {
        int minn = INF;
        int k = -1;
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && minn > cost[j])
            {
                minn = cost[j];
                k = j;
            }
        }
        if(minn == INF) return -1;
        ans += minn;
        vis[k] = 1;
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && cost[j] > a[k][j]) cost[j] = a[k][j];
        }
    }
    return ans;
}

int main()
{
    memset(a,0x3f,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u][v] = a[v][u] = w;
    }
    printf("%d\n",prim());
    return 0;
}
