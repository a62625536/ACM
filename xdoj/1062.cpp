#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,t,a[100005];

int main()
{
	while(~scanf("%d%d",&n,&t))
	{
		for(int i = 1;i <= n;i++)	scanf("%d",&a[i]);
		int sum = 0;
		if(n <= t)
		{
			for(int i = 1;i <= n;i++)	sum += a[i];
			printf("%d\n",sum);
			continue;
		}
		for(int i = 1;i <= t;i++)	sum += a[i];
		int ans = sum;
		for(int l = 1,r = t+1;r <= n;l++,r++)
		{
			sum += a[r];
			sum -= a[l];
			ans = max(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
 
