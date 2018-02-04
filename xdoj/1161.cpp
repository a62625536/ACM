#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;

LL a[1000005] = {0};
int n;

int main()
{
    while(~scanf("%d",&n) && n > 0)
    {
        LL sum1 = 0,sum2 = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&a[i]);
            sum1 += a[i];
        }
        for(int i = 1;i <= n;i++)
        {
            LL t;
            scanf("%lld",&t);
            sum2 += t;
            a[i] = a[i-1]+t-a[i];
        }
        if(sum1 != sum2)
        {
            printf("No way\n");
            continue;
        }
        sort(a,a+n);
        LL t = a[n/2],ans = 0;
        for(int i = 0;i < n;i++)    ans += abs(t-a[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
