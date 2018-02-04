#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;

struct edge
{
	int to,cost;
	friend bool operator>(edge x,edge y)
	{
		return x.cost > y.cost;
	}
}e;
vector<edge> v[11005];
int n,m,k,a[1005][1005],dis[11005],vis[11005];
priority_queue< edge,vector<edge>,greater<edge> > q;

int dij()
{
	while(!q.empty())	q.pop();
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1] = 0;
	e.to = 1;
	e.cost = 0;
	q.push(e);
	while(!q.empty())
	{
		int now = q.top().to,cost = q.top().cost;
		if(now == (k+1)*n)	return dis[(k+1)*n];
		q.pop();
		if(vis[now])	continue;
		vis[now] = 1;
		for(int i = 0;i < v[now].size();i++)
		{
			e = v[now][i];
			if(e.cost+dis[now] < dis[e.to])
			{
				dis[e.to] = e.cost+dis[now];
				e.cost = dis[e.to];
				q.push(e);
			}
		}

	}
}

int main()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int i = 1;i <= 11000;i++)	v[i].clear();
		memset(a,0x3f,sizeof(a));
		for(int i = 1;i <= m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			a[u][v] = min(a[u][v],w);
			a[v][u] = min(a[v][u],w);
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i == j || a[i][j] == INF)	continue;
				for(int l = 0;l <= k;l++)
				{
					e.to = l*n+j;
					e.cost = a[i][j];
					v[l*n+i].push_back(e);
					if(l != k)
					{
						e.to = (l+1)*n+j;
						e.cost = 0;
						v[l*n+i].push_back(e);
					}
				}
			}
		}
		printf("%d\n",dij());
	}
	return 0;
}
