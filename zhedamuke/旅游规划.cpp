#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[505][505],b[505][505],dis[505],cost[505],vis[505],n,m,s,d;

void dij()
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(cost,0x3f,sizeof(cost));
	dis[s] = 0;
	cost[s] = 0;
	for(int i = 0;i < n;i++)
	{
		int maxdis = INF,maxcost = INF;
		int k = -1;
		for(int j = 0;j < n;j++)
		{
			if(vis[j])	continue;
			if(dis[j] < maxdis || dis[j] == maxdis && cost[j] < maxcost)
			{
				maxdis = dis[j];
				maxcost = cost[j];
				k = j;
			}	
		}
		vis[k] = 1;
		if(k == -1)	break;
		for(int j = 0;j < n;j++)
		{
			if(vis[j])	continue;
			if(dis[j] > dis[k]+a[k][j] || dis[j] == dis[k]+a[k][j] && cost[j] > cost[k]+b[k][j])
			{
				dis[j] = dis[k]+a[k][j];
				cost[j] = cost[k]+b[k][j];
			}
		} 
	}	
}
int main()
{
	memset(a,0x3f,sizeof(a));
	memset(b,0x3f,sizeof(b));
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for(int i = 0;i < m;i++)
	{
		int x,y,z,w;
		scanf("%d%d%d%d",&x,&y,&z,&w);
		a[x][y] = a[y][x] = z;
		b[x][y] = b[y][x] = w;
	}
	dij();
	printf("%d %d\n",dis[d],cost[d]);
	return 0;
}
