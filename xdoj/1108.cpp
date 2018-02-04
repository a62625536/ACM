#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int a[1000005];

int main()
{
    a[0] = a[1] = 0;
    for(int i = 2;i <= 1000000;i++)
    {
        if(i%2) a[i] = a[i-1]+1;
        else    a[i] = a[i/2]+1;
    }
    for(int i = 2;i <= 1000000;i++) a[i] += a[i-1];
    int x,y;
    while(~scanf("%d%d",&x,&y)) printf("%d\n",a[y]-a[x-1]);
    return 0;
}
