#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 1000000007
#define LL long long
using namespace std;

int n,m;

LL qmod(LL a, LL b, LL c)
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
        mm = mm*(m-i)%MOD;
        nn = nn*(n-i)%MOD;
    }
    return mm*qmod(nn,MOD-2,MOD)%MOD;
}

LL lucas(LL m,LL n)
{
    LL ans = 1;
    while(m && n && ans)
    {
        ans = ans%MOD*c(m%MOD,n%MOD)%MOD;
        n /= MOD;
        m /= MOD;
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    printf("%lld\n",lucas(n+m-2,n-1));
    return 0;
}
