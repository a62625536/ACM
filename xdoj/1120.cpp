#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct task
{
	int t,v;
}a[1005];
int n,vis[1005] = {0};

bool cmp(task x,task y)
{
	return x.v > y.v;
}
int main()
{
	scanf("%d",&n);
	int t = 0,sum = 0,ans = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].t);
		t = max(a[i].t,t);
	}
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].v);
		sum += a[i].v;
	}
	sort(a+1,a+1+n,cmp);
	for(int i = t;i >= 1;i--)
	{
		for(int j = 1;j <= n;j++)
		{
			if(!vis[j] && i <= a[j].t)
			{
				ans += a[j].v;
				vis[j] = 1;
				break;
			}
		}
	}
	printf("%d\n",sum-ans);
	return 0;
} 
