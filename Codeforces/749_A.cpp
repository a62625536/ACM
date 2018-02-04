#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(n%2 == 0)
    {
        n /= 2;
        printf("%d\n",n);
    }
    else
    {
        n = (n-3)/2;
        printf("%d\n3 ",n+1);
    }
    while(n--)  printf("2 ");
    printf("\n");
    return 0;
}
