#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define MOD (long long)(1e9+7)
using namespace std;

int x,y,k;
LL fac[2000005];

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

LL inv(LL x)
{
    return PowerMod(x,MOD-2,MOD);
}

int main()
{
    fac[1] = 1;
    for(int i = 2;i <= 2000000;i++) fac[i] = fac[i-1]*i%MOD;
    while(~scanf("%d%d%d",&x,&y,&k))
    {
        if(y == k)  printf("1\n");
        else if(y < k)  printf("0\n");
        else    printf("%lld\n",fac[x+y]*inv(fac[x+k])%MOD*inv(fac[y-k])%MOD);
    }
    return 0;
}
