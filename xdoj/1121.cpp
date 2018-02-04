#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long a[65],n,k;

int f(long long x,long long y)
{
    if(x == 1)  return 1;
    if(y <= a[x-1]) return f(x-1,y)^1;
    if(y == a[x-1]+1)   return 1;
    return f(x-1,a[x]-y+1);
}

int main()
{
    a[1] = 1;
    for(int i = 2;i <= 64;i++)  a[i] = a[i-1]*2+1;
    while(~scanf("%lld%lld",&n,&k))
    {
        int ans;
        if(n <= 60) ans = f(n,k);
        else
        {
            ans = f(60,k);
            if(n&1)    ans ^= 1;
        }
        if(ans) printf("srO\n");
        else    printf("Orz\n");
    }
    return 0;
}
