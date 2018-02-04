#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[50005];

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    long long ans = 0,sum = 0;
    for(int i = 1;i <= n;i++)
    {
        sum += a[i];
        if(sum < 0) sum = 0;
        else    ans = max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}
