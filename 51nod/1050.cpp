#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[50005];

int main()
{
    scanf("%d",&n);
    long long sum = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    long long ans = 0,now = 0;
    for(int i = 1;i <= n;i++)
    {
        now += a[i];
        if(now < 0) now = 0;
        else    ans = max(ans,now);
    }
    long long ans1 = 0;
    now = 0;
    for(int i = 1;i <= n;i++)   a[i] = -a[i];
    for(int i = 1;i <= n;i++)
    {
        now += a[i];
        if(now < 0) now = 0;
        else    ans1 = max(ans1,now);
    }
    printf("%lld\n",max(ans,sum+ans1));
    return 0;
}
