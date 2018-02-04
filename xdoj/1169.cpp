#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int f(long long x)
{
    if(x&1) return 0;
    else    return f(x/2)^1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long x;
        scanf("%d",&x);
        if(f(x) == 0)   printf("First Box\n");
        else    printf("Second Box\n");
    }
}
