#include<iostream>
#include<string>
#include<cstdio>
#define INF 0x3f3f3f3f
using namespace std;

int a[1005],n,m,sizee = 0;

void insertt(int x)
{
    sizee++;
    int i;
    for(i = sizee;a[i/2] > x;i /= 2)    a[i] = a[i/2];
    a[i] = x;
}
int main()
{
    a[0] = -INF;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        int temp;
        scanf("%d",&temp);
        insertt(temp);
    }
    for(int i = 1;i <= m;i++)
    {
        int temp;
        scanf("%d",&temp);
        printf("%d",a[temp]);
        while(temp/2)
        {
            temp /= 2;
            printf(" %d",a[temp]);
        }
        printf("\n");
    }
    return 0;
}
