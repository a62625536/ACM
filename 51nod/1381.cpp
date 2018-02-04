#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

long long n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",2*n);
    }
    return 0;
}
