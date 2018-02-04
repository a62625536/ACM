#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define MOD 1000000007
using namespace std;

LL PowerMod(LL a, LL b, LL c)
{
    LL ans = 1;
    a = a % c;
    while(b)
    {
        if(b&1) ans = (ans*a)%c;
        b = b>>1;
        a = (a*a)%c;
    }
    return ans;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n == 1)	printf("1\n");
		else if(n%2)	printf("%lld\n",PowerMod(2,n-1,MOD));
		else	printf("%lld\n",(PowerMod(2,n-1,MOD)+PowerMod(2,n/2-1,MOD))%MOD);
	}
	return 0;
}
