#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;

int main()
{
	LL x1,y1,x2,y2,r,X1,Y1,X2,Y2;
	while(~scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&r))
	{
		X1 = y1+x1;
		Y1 = y1-x1;
		X2 = y2+x2;
		Y2 = y2-x2;
		LL a = max(0LL,2*r+2-abs(X1-X2)),b = max(0LL,2*r+2-abs(Y1-Y2));
		LL sub = a*b?(a*b-a-b+2)/2:0;
		printf("%lld\n",2*(2*r*r+2*r+1)-sub);
	}
	return 0;
}
