#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define LL long long
using namespace std;

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
    LL a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld\n",qmod(a,b,c));
    return 0;
}
