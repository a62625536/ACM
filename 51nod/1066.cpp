#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(n <= k || n%(k+1))  printf("A\n");
        else    printf("B\n");
    }
    return 0;
}
