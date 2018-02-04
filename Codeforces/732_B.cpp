#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k,a[505];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    int last = a[1],sum = 0;
    for(int i = 2;i <= n;i++)
    {
        if(a[i]+last < k)
        {
            sum += k-a[i]-last;
            a[i] = k-last;
        }
        last = a[i];
    }
    printf("%d\n",sum);
    for(int i = 1;i <= n;i++)   printf("%d ",a[i]);
    return 0;
}
