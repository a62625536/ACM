#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define MOD 1000000007
using namespace std;

LL a,b,n;
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
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&n,&b);
		int ans = b;
		for(int i = 2;i <= n;i++)
		{
			b = (b*b+MOD-2)%(MOD-1);
			ans = ans*b%(MOD-1);
		}
		printf("%lld\n",PowerMod(a,ans,MOD));
	}
	return 0;
} 
