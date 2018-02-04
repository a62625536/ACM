#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[100005],n,k;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++)	scanf("%d",&a[i]);
		int l = 0,now = 0;
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			now += a[i];
			while(now > k)	now -= a[++l];
			ans += i-l;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
