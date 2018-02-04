#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long maxx = 0,sum = 0,temp;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lld",&temp);
			maxx = max(maxx,temp);
			sum += temp;
		}
		printf("%lld\n",min(sum/2,sum-maxx));
	} 
	return 0;
}
