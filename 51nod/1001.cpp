#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k,a[50005];

int main()
{
    scanf("%d%d",&k,&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int last = n,flag = 0;
    for(int i = 1;i < last;i++)
    {
        int t = lower_bound(a+1,a+1+last,k-a[i])-a;
        if(t <= i)  break;
        else if(t > last)   continue;
        else
        {
            if(a[t] == k-a[i])
            {
                printf("%d %d\n",a[i],a[t]);
                flag = 1;
            }
            last = t;
        }
    }
    if(!flag)   printf("No Solution\n");
    return 0;
}
