#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long a[200005],b[200005],c[200005],num[35] = {0};
int n;

int main()
{
    scanf("%d",&n);
    long long sum = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%I64d",&b[i]);
        sum += b[i];
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%I64d",&c[i]);
        sum += c[i];
    }
    int flag = 1;
    if(sum%(2*n))   flag = 0;
    else
    {
        sum /= 2*n;
        for(int i = 1;i <= n;i++)
        {
            long long t = b[i]+c[i];
            if((t-sum)%n)
            {
                flag = 0;
                break;
            }
            else    a[i] = (t-sum)/n;
        }
    }
    if(flag)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;(1<<j) <= a[i];j++)
            {
                if(a[i]&(1<<j))  num[j]++;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            long long t = 0;
            for(int j = 0;(1<<j) <= a[i];j++)
            {
                if(a[i]&(1<<j)) t += num[j]*(1LL<<j);
            }
            if(t != b[i])   flag = 0;
        }
    }
    if(flag)
    {
        for(int i = 1;i <= n;i++)   printf("%I64d ",a[i]);
        printf("\n");
    }
    else    printf("-1\n");
    return 0;
}
