#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,h,op[1005],a[1005],hh[1005];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,-1,sizeof(a));
		scanf("%d",&n);
		for(int i = 0;i < n;i++)	scanf("%d",&op[i]);
		scanf("%d",&m);
		for(int i = 1;i <= m;i++)	scanf("%d",&hh[i]);
		int pos;
		for(int i = 1;i <= m;i++)
		{
			scanf("%d",&pos);
			if(pos <= n)	a[pos] = hh[i];
		}
		scanf("%d",&h);
		int flag = 1,now = 0;
		while(now < n)
		{
			if(op[now] == 1)	h++;
			else if(op[now] == 0)	h--;
			if(h == 0 || a[now] != -1 && h >= a[now])
			{
				flag = 0;
				break;
			}
			now++;
		}
		if(flag)	printf("V8Orz\n");
		else	printf("%d\n",now);
	}
	return 0;
}
