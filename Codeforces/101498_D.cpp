#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long a[100005],fac[100005],inv[100005];

long long c(int n,int m)
{
    return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}

int main()
{
    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2;i <= 100000;i++)  inv[i] = inv[MOD%i]*(MOD-MOD/i)%MOD;
    for(int i = 2;i <= 100000;i++)  inv[i] = inv[i-1]*inv[i]%MOD;
    fac[0] = 1;
    for(int i = 1;i <= 100000;i++)  fac[i] = fac[i-1]*i%MOD;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",2*c(x-1,y)%MOD);
    }
    return 0;
}

