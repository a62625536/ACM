#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD (long long)(1e9+7)
#define LL long long
using namespace std;

LL fac[2000005],inv[2000005],n,m,k;

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

inline LL c(LL n,LL m)
{
    if(m > n)   return 0;
    return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}

int main()
{
	fac[0] = 1;
	for(int i = 1;i <= 2000000;i++) fac[i] = fac[i-1]*i%MOD;
    inv[2000000] = PowerMod(fac[2000000],MOD-2,MOD);
    for(int i = 1999999;i >= 0;i--) inv[i] = inv[i+1]*(i+1)%MOD;
	while(~scanf("%lld%lld%lld",&n,&m,&k))
    {
        LL ans = c(n+m-1,m),x = -1;
        for(int i = 1;i <= n;i++,x = -x)
        {
            LL t = m-i*(k+1);
            if(t < 0)   break;
            ans = (ans+x*(c(n,i)*c(n+t-1,t)%MOD)+MOD)%MOD;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
