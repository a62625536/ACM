#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct vedio
{
	int l,r;
}a[1005];
int n;

bool cmp(vedio x,vedio y)
{
	return x.r < y.r;
}

int main()
{
	while(scanf("%d",&n) && n)
	{
		for(int i = 1;i <= n;i++)	scanf("%d%d",&a[i].l,&a[i].r);
		sort(a+1,a+1+n,cmp);
		int ans = 1,time = a[1].r,now = 2;
		for(;now <= n;now++)
		{
			if(time > a[now].l)	continue;
			time = a[now].r;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
