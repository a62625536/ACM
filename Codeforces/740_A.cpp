#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long n,a,b,c;

int main()
{
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    n %= 4;
    if(n == 0)  printf("0\n");
    else if(n == 1)
    {
        long long ans = min(3*a,a+b);
        ans = min(ans,c);
        printf("%I64d\n",ans);
    }
    else if(n == 2)
    {
        long long ans = min(2*a,b);
        ans = min(ans,2*c);
        printf("%I64d\n",ans);
    }
    else
    {
        long long ans = min(a,b+c);
        ans = min(ans,3*c);
        printf("%I64d\n",ans);
    }
    return 0;
}
