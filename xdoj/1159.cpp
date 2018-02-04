#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int n,m,t,a[305][305],ok[305];

int main()
{
    while(~scanf("%d%d%d",&n,&m,&t))
    {
        memset(a,0x3f,sizeof(a));
        memset(ok,0,sizeof(ok));
        for(int i = 0;i < n;i++)    a[i][i] = 0;
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(u == v)  continue;
            a[u][v] = min(a[u][v],w);
        }
        while(t--)
        {
            int o;
            scanf("%d",&o);
            if(o == 0)
            {
                int x;
                scanf("%d",&x);
                if(ok[x])   printf("lab %d has been repaired!\n",x);
                else
                {
                    ok[x] = 1;
                    for(int i = 0;i < n;i++)
                    {
                        for(int j = 0;j < n;j++)
                        {
                            if(!ok[i] || !ok[j])    continue;
                            a[j][x] = min(a[j][x],a[j][i]+a[i][x]);
                        }
                    }
                    for(int i = 0;i < n;i++)
                    {
                        for(int j = 0;j < n;j++)
                        {
                            if(!ok[i] || !ok[j])    continue;
                            a[x][j] = min(a[x][j],a[x][i]+a[i][j]);
                        }
                    }
                    for(int i = 0;i < n;i++)
                    {
                        for(int j = 0;j < n;j++)
                        {
                            if(!ok[i] || !ok[j])    continue;
                            a[i][j] = min(a[i][j],a[i][x]+a[x][j]);
                        }
                    }
                }
            }
            else
            {
                int u,v;
                scanf("%d%d",&u,&v);
                if(!ok[u] || !ok[v])    printf("help %d %d\n",u,v);
                else if(a[u][v] == INF)    printf("no path\n");
                else    printf("%d\n",a[u][v]);
            }
        }
    }
    return 0;
}
