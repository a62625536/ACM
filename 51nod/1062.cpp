#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long ans[100005],a[100005];
int n;

int main()
{
    a[0] = 0;
    a[1] = 1;
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 1;i <= 50000;i++)
    {
        a[2*i] = a[i];
        a[2*i+1] = a[i]+a[i+1];
        ans[2*i] = max(ans[2*i-1],a[2*i]);
        ans[2*i+1] = max(ans[2*i],a[2*i+1]);
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
