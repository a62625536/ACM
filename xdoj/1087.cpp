#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,w,V;
struct aa
{
	int v;
	double a;
}a[1005];

bool cmp(aa x,aa y)
{
	return x.a < y.a;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d",&a[i].v,&w);
			a[i].a = (double)w/a[i].v;
		}
		scanf("%d",&V);
		sort(a+1,a+1+n,cmp);
		int now = n;
		double ans = 0;
		while(V && now >= 1)
		{
			if(V > a[now].v)
			{
				ans += a[now].a*a[now].v;
				V -= a[now].v;
				now--;
			}
			else
			{
				ans += V*a[now].a;
				break;
			}
		}
		printf("%.4f\n",ans);
	}
	return 0;
}
