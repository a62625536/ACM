#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int k,n;

int main()
{
    while(~scanf("%d%d",&k,&n))
    {
        long long ans = 0,temp = 1;
        while(n)
        {
            ans += temp*(n%2);
            n /= 2;
            temp *= k;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
