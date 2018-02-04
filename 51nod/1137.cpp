#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[105][105],b[105][105],ans[105][105] = {0};

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   scanf("%d",&a[i][j]);
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   scanf("%d",&b[i][j]);
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= n;k++)   ans[i][j] += a[i][k]*b[k][j];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
