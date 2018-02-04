#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long n;
long long a[60000];

int main()
{
    int cnt = 0;
    for(long long i = 1;i <= 1e18+1000;i *= 2)
    {
        for(long long j = 1;i*j <= 1e18+1000;j *= 3)
        {
            for(long long k = 1;i*j*k <= 1e18+1000;k *= 5)    a[++cnt] = i*j*k;
        }
    }
    sort(a+1,a+1+cnt);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",a[lower_bound(a+2,a+1+cnt,n)-a]);
    }
    return 0;
}
