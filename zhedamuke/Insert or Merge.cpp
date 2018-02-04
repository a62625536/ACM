#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[105],aa[105],b[105],n;

bool ok(int x[],int y[])
{
    for(int i = 1;i <= n;i++)
    {
        if(x[i] != y[i])    return 0;
    }
    return 1;
}

void printff(int x[])
{
    printf("%d",x[1]);
    for(int i = 2;i <= n;i++)   printf(" %d",x[i]);
    printf("\n");
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        aa[i] = a[i];
    }
    for(int i = 1;i <= n;i++)   scanf("%d",&b[i]);
    int flag = 0;
    for(int i = 2;i <= n;i++)
    {
        sort(a+1,a+i+1);
        if(ok(a,b))
        {
            sort(a+1,a+i+2);
            printf("Insertion Sort\n");
            printff(a);
            return 0;
        }
    }
    for(int i = 2;i <= n;i *= 2)
    {
        int j;
        for(j = 1;j+i <= n+1;j += i)  sort(aa+j,aa+j+i);
        sort(aa+j,aa+n+1);
        if(ok(aa,b))
        {
            int j;
            for(j = 1;j+2*i <= n+1;j += 2*i)  sort(aa+j,aa+j+2*i);
            sort(aa+j,aa+n+1);
            printf("Merge Sort\n");
            printff(aa);
            return 0;
        }
    }
}
