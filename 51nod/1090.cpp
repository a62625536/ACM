#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[1005];

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int flag = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            int t = lower_bound(a+j+1,a+1+n,-a[i]-a[j])-a;
            if(t <= n && a[t]+a[i]+a[j] == 0)
            {
                flag = 1;
                printf("%d %d %d\n",a[i],a[j],a[t]);
            }
        }
    }
    if(!flag)   printf("No Solution\n");
    return 0;
}
