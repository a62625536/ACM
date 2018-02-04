#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[100005],sum[100005];

int main()
{
	int n,m,l,r,k;
	while(~scanf("%d",&n))
	{
		long long summ = 0;
		memset(sum,0,sizeof(sum));
		for(int i = 1;i <= n;i++)	scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i = 1;i <= m;i++)
		{
			scanf("%d%d%d",&l,&r,&k);
			sum[l+1] -= k;
			sum[r+1] += k;
		}
		for(int i = 1;i <= n;i++)
		{
			sum[i] += sum[i-1];
			a[i] += sum[i];
			summ += a[i];
		}
		int ave = summ/n;
		for(int i = 1;i <= n;i++)	a[i] -= ave;
		summ = 0;
		for(int i = 1;i <= n;i++)	summ += (long long)a[i]*a[i];
		printf("%lld\n",summ);
	}
	return 0;
}
