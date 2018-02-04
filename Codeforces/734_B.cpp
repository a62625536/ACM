#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int x = min(a,c);
    x = min(x,d);
    int sum = x*256;
    a -= x;
    x = min(a,b);
    sum += x*32;
    printf("%d\n",sum);
    return 0;
}
