#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        n %= 7;
        if(n == 0 || n == 2)    printf("B\n");
        else    printf("A\n");
    }
    return 0;
}
