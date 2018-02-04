#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int l,r;
double x[305];

int main()
{
	while(~scanf("%d%d",&l,&r))
	{
		if(r <= 210)
		{
			printf("stupid\n");
			continue;
		}
		int m = r-l+1,ok = 210-l+1;
		for(int i = 1;i <= m;i++)	x[i] = 1;
		double now = 300;
		int ans = 0;
		while(m - now <= ok-1e-6)
		{
			now = 0;
			for(int i = 1;i <= m-1;i++)
			{
				x[i] *= (double)i/m;
				now += x[i];
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
