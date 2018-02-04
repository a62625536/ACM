#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,a[1000005];

int main()
{
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for(int i = 4;i <= 1000000;i++) a[i] = (a[i-1]+a[i-2]+a[i-3])%10007;
    while(~scanf("%d",&n))  printf("%d\n",a[n]);
    return 0;
}

