#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int vis[15],a[15],n,k,ans;

void dfs(int num,int v)
{
	if(num == n)
	{
		if(abs(v-a[1]) <= k)	ans++;
		return;
	}
	for(int i = 2;i <= n;i++)
	{
		if(vis[i])	continue;
		if(abs(v-a[i]) > k)	continue;
		vis[i] = 1;
		dfs(num+1,a[i]);
		vis[i] = 0;
	}
}

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		memset(vis,0,sizeof(vis));
		ans = 0;
		for(int i = 1;i <= n;i++)	scanf("%d",&a[i]);
		dfs(1,a[1]);
		printf("%d\n",ans);
	}
	return 0;
}
