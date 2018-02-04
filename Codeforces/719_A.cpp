#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100],n;

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    if(a[n] == 15)
    {
        printf("DOWN\n");
        return 0;
    }
    if(a[n] == 0)
    {
        printf("UP\n");
        return 0;
    }
    if(n == 1)
    {
        printf("-1\n");
        return 0;
    }
    if(a[n-1] < a[n])   printf("UP\n");
    else    printf("DOWN\n");
    return 0;
}
