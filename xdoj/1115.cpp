#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define MOD 1000000007
using namespace std;

int a,b,n;
long long ans[10005];

int main()
{
    ans[0] = 2;
    while(~scanf("%d%d%d",&a,&b,&n))
    {
        ans[1] = a;
        for(int i = 2;i <= n;i++)   ans[i] = ((ans[i-1]*a-ans[i-2]*b%MOD)+MOD)%MOD;
        printf("%lld\n",ans[n]);
    }
    return 0;
}
