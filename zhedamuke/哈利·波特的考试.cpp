#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std; 

int g[105][105],n,m;

int main()
{
	scanf("%d%d",&n,&m);
	memset(g,0x3f,sizeof(g));
	for(int i = 1;i <= m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a][b] = c;
		g[b][a] = c;
	} 
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(g[i][k]+g[k][j] < g[i][j])	g[i][j] = g[i][k]+g[k][j];
			}
		}
	}
	int num = -1,ans = INF;
	for(int i = 1;i <= n;i++)
	{
		int maxx = 0,flag = 1;
		for(int j = 1;j <= n;j++)
		{
			if(i == j)	continue;
			maxx = max(maxx,g[i][j]);
		}
		if(maxx < ans)
		{
			num = i;
			ans = maxx;
		}
	}
	if(num == -1)	printf("0\n");
	else	printf("%d %d\n",num,ans);
	return 0;
}
