#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MOD 100000000
using namespace std;

int n;
long long a[10000];

int main()
{
    int cnt = 0;
    scanf("%d",&n);
    a[0] = 1;
    for(int i = 1;i <= n;i++)
    {
        long long t = 0;
        for(int j = 0;j <= cnt;j++)
        {
            a[j] = a[j]*i+t;
            t = a[j]/MOD;
            a[j] %= MOD;
        }
        if(t > 0)   a[++cnt] = t;
    }
    printf("%lld",a[cnt]);
    for(int i = cnt-1;i >= 0;i--)   printf("%.8lld",a[i]);
    printf("\n");
    return 0;
}
