#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

struct aaa
{
	int num,w;
}a[10];
int w[10];

bool cmp(aaa x,aaa y)
{
	if(x.w == y.w)	return x.num > y.num;
	return x.w < y.w;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i = 1;i <= 9;i++)	a[i].num = i;
		for(int i = 1;i <= 9;i++)
		{
			scanf("%d",&a[i].w);
			w[i] = a[i].w;
		}
		sort(a+1,a+10,cmp);
		if(n < a[1].w)
		{
			printf("-1\n");
			continue;
		}
		int cnt = n/a[1].w,temp = n%a[1].w,now = 9;
		while(n)
		{
			if(n < a[1].w)	break;
			for(;temp+a[1].w < w[now];now--);
			if(temp+a[1].w >= w[now])
			{
				printf("%d",now);
				n -= w[now];
				temp = temp+a[1].w-w[now];
			}
			else
			{
				printf("%d",a[1].w);
				n -= a[1].w;
			}
		}
		printf("\n");
	}
	return 0;
}
