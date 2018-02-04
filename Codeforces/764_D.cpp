#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    printf("YES\n");
    scanf("%d",&n);
    while(n--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if((a&1) && (b&1))  printf("1\n");
        else if(!(a&1) && (b&1))    printf("2\n");
        else if((a&1) && !(b&1))    printf("3\n");
        else    printf("4\n");
    }
    return 0;
}
