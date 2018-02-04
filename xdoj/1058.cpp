#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;

LL a[100005];
int n,m,u,v,w;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(a,0,sizeof(a));
		for(int i = 1;i <= m;i++)
		{
			scanf("%d%d%ld",&u,&v,&w);
			a[u] += w;
			a[v] += w;
		}
		LL ans = 0;
		for(int i = 1;i <= n;i++)	ans += a[i] > 0?a[i]:-a[i];
		ans /= 2;
		printf("%lld\n",ans);
	}
	return 0;
}
