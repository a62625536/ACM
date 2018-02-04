#include <bits/stdc++.h>
using namespace std;

int vis[1000005] = {0},prime[1000005],num[105] = {0};
long long n;

int main()
{
    int cnt = 0;
    for(int i = 2;i < 1000005;i++)
    {
        if(!vis[i])  prime[++cnt] = i;
        for(int j = 1;i*prime[j] < 1000005 && j <= cnt;j++)
        {
            vis[prime[j]*i] = 1;
            if(!(i%prime[j]))   break;
        }
    }
    for(int i = 1;i <= 100;i++)
    {
        for(int j = 0;j <= i;j++)   num[i] += (j+1)*(i-j+1);
    }
    while(~scanf("%lld",&n))
    {
        long long ans = 1;
        for(int i = 1;(long long)prime[i]*prime[i] <= n;i++)
        {
            if(n%prime[i] == 0)
            {
                int t = 0;
                while(n%prime[i] == 0)
                {
                    t++;
                    n /= prime[i];
                }
                ans *= num[t];
            }
        }
        if(n != 1)  ans *= 4;
        printf("%lld\n",ans);
    }
	return 0;
}
