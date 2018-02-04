#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,u,v,vis[15],sco[15],ans,k;
vector<int> pre[15];

void dfs(int x,int sum)
{
	if(x == 0)
	{
		ans = max(ans,sum);
		return;
	}
	for(int i = 1;i <= 10;i++)
	{
		if(vis[i])	continue;
		int flag = 1;
		for(int j = 0;j < pre[i].size();j++)
		{
			if(!vis[pre[i][j]])
			{
				flag = 0;
				break;
			}
		}
		if(!flag)	continue;
		vis[i] = 1;
		dfs(x-1,sum+sco[i]);
		vis[i] = 0;
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= 10;i++)	pre[i].clear();
		while(n--)
		{
			scanf("%d%d",&u,&v);
			pre[v].push_back(u);
		}
		for(int i = 1;i <= 10;i++)	scanf("%d",&sco[i]);
		scanf("%d",&k);
		ans = 0;
		dfs(k/3,0);
		if(ans >= 60)	printf("%d\n",ans);
		else	printf("I chose to die\n");
	}
	return 0;
}
