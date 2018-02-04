#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

long long a,b,c;

int main()
{
    while(~scanf("%lld%lld%lld",&a,&b,&c))
    {
        if(a == 0 && b == 0 && c == 0)
        {
            printf("inf\n");
            continue;
        }
        if(a == 0 && b == 0)
        {
            printf("0\n");
            continue;
        }
        long long x = b*b-4*a*c;
        if(x == 0 || a == 0)   printf("1\n");
        else if(x > 0) printf("2\n");
        else    printf("0\n");
    }
    return 0;
}
