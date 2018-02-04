#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100005],n;

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        long long ans = 0;
        while(n)
        {
            if(n == 1)
            {
                ans += a[1];
                break;
            }
            if(n == 2)
            {
                ans += a[2];
                break;
            }
            if(n == 3)
            {
                ans += a[1]+a[2]+a[3];
                break;
            }
            else
            {
                ans += min(2*a[1]+a[n]+a[n-1],a[1]+2*a[2]+a[n]);
                n -= 2;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
