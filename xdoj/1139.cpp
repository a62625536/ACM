#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,f[100],sum[100];

int main()
{
    f[0] = 0;
    f[1] = 1;
    sum[1] = 1;
    for(int i = 2;i <= 100;i++)
    {
        f[i] = f[i-1]+f[i-2];
        sum[i] = sum[i-1]+f[i];
    }
    while(~scanf("%lld",&n))
    {
        if(n == 1 || n == 2 || n == 3)  printf("1 1\n");
        else
        {
            int x = lower_bound(sum,sum+100,n)-sum;
            long long y = n-sum[x-1];
            if(y > f[x-1])  printf("%d %lld\n",x,y);
            else    printf("%d %lld\n",x-1,f[x-1]);
        }
    }
    return 0;
}
