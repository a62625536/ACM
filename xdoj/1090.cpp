#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct line
{
	int next,w;
}l;
vector<line> v[10005];
int n;

int dfs(int x)
{
	int sum = 0;
	for(int i = 0;i < v[x].size();i++)	sum = max(sum,dfs(v[x][i].next)+v[x][i].w);
	return sum;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 1;i <= 10000;i++)	v[i].clear();
		for(int i = 1;i <= n;i++)
		{
			int u;
			scanf("%d%d%d",&u,&l.next,&l.w);
			v[u].push_back(l);
		}
		printf("%d\n",dfs(1));
	}
	return 0;
}
