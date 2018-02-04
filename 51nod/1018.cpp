#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[50005];

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++)   printf("%d\n",a[i]);
    return 0;
}
