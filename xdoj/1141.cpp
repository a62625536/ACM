#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long x,y,a;

int main()
{
    while(~scanf("%ld %ld %ld",&x,&y,&a))
    {
        a %= x+y;
        if(a == 0)
        {
            printf("light\n");
            continue;
        }
        while(a)
        {
            a -= x;
            if(a <= 0)
            {
                printf("wanshen\n");
                break;
            }
            a -= y;
            if(a <= 0)
            {
                printf("light\n");
                break;
            }
        }
    }
    return 0;
}
