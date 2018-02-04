#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

LL n,m;

LL gcd(LL x,LL y)
{
    return y?gcd(y,x%y):x;
}

LL c(LL x,LL y)
{
    return (y*(y+1)*(2*y+1))/6-((x-1)*x*(2*x-1))/6;
}

int main()
{
    while(~scanf("%lld%lld",&n,&m) && n && m)
    {
        LL ans = 0;
        int now = 1;
        while(now <= n)
        {
            int t = n/now,endd = min(m,n/t);
            ans += t*c(now,endd);
            if(endd == m)    break;
            now = endd +1;
        }
        LL x = n*m;
        LL g = gcd(ans,x);
        printf("%lld/%lld\n",ans/g,x/g);
    }
}
