#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[200005];

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    int flag = 1;
    for(int i = 1,j = n;i < j;i++,j--)
    {
        if(flag)    swap(a[i],a[j]);
        flag = !flag;
    }
    for(int i = 1;i <= n;i++)   printf("%d ",a[i]);
    return 0;
}
