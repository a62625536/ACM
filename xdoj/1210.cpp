#include<bits/stdc++.h>
#define MOD 19260817
using namespace std;

int n,q,a[55];
long long euler(long long n)
{
    long long ans = 1;
    for(int i = 2;(long long)i*i <= n;i++)
    {
        if(n%i == 0)
        {
            n /= i;
            ans *= i-1;
            while(n%i == 0)
            {
                n /= i;
                ans *= i;
            }
        }
    }
    if(n > 1)     ans *= n-1;
    return ans;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)
        {
            int x;
            scanf("%d",&x);
            a[i] = euler(x);
        }
        scanf("%d",&q);
        while(q--)
        {
            long long ans = 1;
            int x;
            scanf("%d",&x);
            for(int i = 1;i <= n;i++)   ans = ans*(__gcd(x-1,a[i])+1)%MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
