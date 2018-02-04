#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[505][505] = {0};

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   scanf("%d",&a[i][j]);
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   a[i][j] = max(a[i-1][j],a[i][j-1])+a[i][j];
    }
    printf("%d\n",a[n][n]);
    return 0;
}
