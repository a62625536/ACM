#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;

LL a,b,c,y;

LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):a;
}

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

LL euler(LL n)
{
    LL res = n,a = n;
    for(LL i = 2;i*i <= a;i++)
    {
        if(a%i == 0)
        {
            res = res/i*(i-1);
            while(a%i == 0)    a /= i;
        }
    }
    if(a > 1)    res = res/a*(a-1);
    return res;
}

int main()
{
    while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&y))
    {
        if(log(b) < 9/c)
        {
            printf("%lld\n",PowerMod(a,PowerMod(b,c,1e9+7),y));
        }
        else    printf("%lld\n",PowerMod(a,PowerMod(b,c,euler(y)),y)*PowerMod(gcd(a,y),euler(y),y)%y);
    }
    return 0;
}
