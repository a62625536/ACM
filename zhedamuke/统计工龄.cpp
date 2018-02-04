#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[55] = {0},n;

int main()
{
    scanf("%d",&n);
    int t;
    while(n--)
    {
        scanf("%d",&t);
        a[t]++;
    }
    for(int i = 0;i <= 50;i++)
    {
        if(a[i])    printf("%d:%d\n",i,a[i]);
    }
    return 0;
}
