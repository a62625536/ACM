#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	long long a1,a2,b1,b2,c1,c2,d1,d2;
	while(~scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2))
	{
		long long x1 = a1*d1,x2 = a2*d2,y1 = b1*c1,y2 = b2*c2;
		if(x1 > y2 || x2 < y1)	printf("NO\n");
		else	printf("YES\n");
	}
	return 0;
}
