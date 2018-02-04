#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define LL long long
using namespace std;

int a,b,k,x,y;

LL qmod(LL a, LL b, LL c)
{
    LL ans = 1;
    a = a%c;
    while(b)
    {
        if(b&1)    ans = ans*a%c;
        b >>= 1;
        a = a*a%c;
    }
    return ans;
}

int e_gcd(int a,int b)
{
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int ans = e_gcd(b,a%b),temp = x;
    x = y;
    y = temp-a/b*y;
    return ans;
}

int inv(int a,int mod)
{
    int gcd = e_gcd(a,mod);
    if(gcd != 1)    return -1;
    return (x%mod+mod)%mod;
}

int main()
{
    while(~scanf("%d%d%d",&a,&b,&k))
    {
        LL x = qmod(a,b,k-1);
        if(x == 0)  x = k-1;
        LL t = inv(k-1,MOD);
        printf("%lld\n",(qmod(a,b,MOD)-x+MOD)%MOD*t%MOD);
    }
    return 0;
}
