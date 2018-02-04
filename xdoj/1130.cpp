#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
#define MOD 542
using namespace std;

int p,d,n;

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

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&p,&d,&n);
        LL ans = qmod(2,n,MOD)*p%MOD;
        ans = (qmod(2,n-1,MOD)*d*n+ans)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
