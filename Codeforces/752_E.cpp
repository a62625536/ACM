#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k,a[1000005],dp[10000007];

bool ok(long long x)
{
    for(long long i = 1;i < x && i <= 10000000;i++)    dp[i] = 0;
    for(long long i = x;i < 2*x && i <= 10000000;i++)  dp[i] = 1;
    for(long long i = 2*x;i <= 10000000;i++)
        dp[i] = dp[i/2]+dp[i/2+i%2];
    int t = k;
    for(int i = 1;i <= n;i++)
    {
        t -= dp[a[i]];
        if(t <= 0)  return 1;
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&k);
    long long sum = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    if(sum < k)
    {
        printf("-1\n");
        return 0;
    }
    long long l = 1,r = sum/k;
    while(l < r)
    {
        long long mid = (l+r+1)/2;
        if(ok(mid)) l = mid;
        else    r = mid-1;
    }
    printf("%I64d\n",l);
    return 0;
}
