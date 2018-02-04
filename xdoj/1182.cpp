#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
#define MOD 23333333333
using namespace std;

LL n,m;

LL qmul(LL a, LL b, LL c)
{
    LL ans = 0;
    a = a%c;
    while(b)
    {
        if(b&1)    ans = (ans+a)%c;
        b >>= 1;
        a = (a+a)%c;
    }
    return ans;
}

int main()
{
    while(~scanf("%lld%lld",&n,&m))
    {
        LL x = m/3,y = m%3,ans = 0;
        if(x%2) ans = qmul(x*3,(2*n+x+1)/2,MOD);
        else    ans = qmul(x*3/2,2*n+x+1,MOD);
        for(int i = 0;i < y;i++)   ans = (ans+n+x+i)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
