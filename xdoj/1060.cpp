#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[25];
int main()
{
    long long x;
    while(~scanf("%lld",&x))
    {
        int cnt = 0;
        if(x%10 >= 5)    x = x/10+1;
        else        x = x/10;
        if(x == 0)
        {
            printf("0.00\n");
            continue;
        }
        while(x)
        {
            a[++cnt] = x%10;
            x /= 10;
        }
        if(cnt > 2)
        {
            for(;cnt > 2;cnt--) printf("%d",a[cnt]);
        }
        else
        {
            printf("0");
        }
        printf(".");
        if(cnt == 1)    printf("0");
        for(;cnt > 0;cnt--) printf("%d",a[cnt]);
        printf("\n");
    }
    return 0;
}
