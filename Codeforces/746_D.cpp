#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k,a,b;

int main()
{
    scanf("%d%d%d%d",&n,&k,&a,&b);
    if(a > b)
    {
        if((long long)k*(b+1) < a)
        {
            printf("NO\n");
            return 0;
        }
        while(b)
        {
            for(int j = 1;j <= k && a > b;j++)
            {
                printf("G");
                a--;
            }
            printf("B");
            b--;
        }
        while(a--)  printf("G");
    }
    else
    {
        if((long long)k*(a+1) < b)
        {
            printf("NO\n");
            return 0;
        }
        while(a)
        {
            for(int j = 1;j <= k && b > a;j++)
            {
                printf("B");
                b--;
            }
            printf("G");
            a--;
        }
        while(b--)  printf("B");
    }
    printf("\n");
    return 0;
}
