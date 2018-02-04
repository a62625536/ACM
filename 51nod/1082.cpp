#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
long long sum[1000005];
bool a[1000005] = {0};

int main()
{
    for(int i = 7;i <= 1000000;i += 7)  a[i] = 1;
    for(int i = 1;i < 1000000;i *= 10)
    {
        for(int j = i*7;j <= 1000000;j += i*10)
        {
            for(int k = 0;k < i;k++)    a[k+j] = 1;
        }
    }
    sum[0] = 0;
    for(int i = 1;i <= 1000000;i++)
    {
        if(a[i])    sum[i] = sum[i-1];
        else    sum[i] = sum[i-1]+(long long)i*i;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%lld\n",sum[n]);
    }
    return 0;
}
