#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	long long x;
	while(~scanf("%lld",&x))
	{
		long long y = sqrt(x);
		if(y*y <= x)	y++;
		if(y%2)	printf("even\n");
		else	printf("odd\n");
	}
	return 0;
}
