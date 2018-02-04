#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

int n;

LL qmod(LL a,LL b,LL c)
{
    LL ans = 1;
    a = a%c;
    while(b)
    {
        if(b%2) ans = ans*a%c;
        b /= 2;
        a = a*a%c;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    printf("%lld\n",qmod(n,n,10));
    return 0;
}
