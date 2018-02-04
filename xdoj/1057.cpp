#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
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

LL c(LL m,LL n)
{
    if(m < n)   return 0;
    if(m == n)  return 1;
    if(n > m-n) n = m-n;
    LL mm = 1,nn = 1;
    for(LL i = 0;i < n;i++)
    {
        mm = mm*(m-i)%10007;
        nn = nn*(n-i)%10007;
    }
    return mm*PowerMod(nn,10005,10007)%10007;
}

LL lucas(LL m,LL n)
{
    LL ans = 1;
    while(m && n && ans)
    {
        ans = ans%10007*c(m%10007,n%10007)%10007;
        n /= 10007;
        m /= 10007;
    }
    return ans;
}

int main()
{
	LL n,m;
	while(~scanf("%lld%lld",&m,&n))	printf("%lld\n",lucas(m+n-1,n));
	return 0;
}
