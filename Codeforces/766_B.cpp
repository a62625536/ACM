#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[100005];

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int flag = 0;
    for(int i = 1;i <= n-2;i++)
    {
        if(a[i]+a[i+1] > a[i+2])    flag = 1;
    }
    if(flag)    printf("YES\n");
    else    printf("NO\n");
    return 0;
}
