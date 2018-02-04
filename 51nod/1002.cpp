#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[505][505];

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)   scanf("%d",&a[i][j]);
    }
    for(int i = n-1;i >= 1;i--)
    {
        for(int j = 1;j <= i;j++)   a[i][j] = max(a[i+1][j],a[i+1][j+1])+a[i][j];
    }
    printf("%d\n",a[1][1]);
    return 0;
}
