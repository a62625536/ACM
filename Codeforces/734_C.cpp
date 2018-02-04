#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long n,k,m,x,s,a[200005],b[200005],c[200005],d[200005];

int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&k,&x,&s);
    for(int i = 1;i <= m;i++)   scanf("%I64d",&a[i]);
    for(int i = 1;i <= m;i++)   scanf("%I64d",&b[i]);
    for(int i = 1;i <= k;i++)   scanf("%I64d",&c[i]);
    for(int i = 1;i <= k;i++)   scanf("%I64d",&d[i]);
    a[0] = x;
    b[0] = 0;
    c[0] = 0;
    d[0] = 0;
    long long ans = n*x;
    for(int i = 0;i <= m;i++)
    {
        if(s < b[i])    continue;
        int ss = s-b[i];
        int t = lower_bound(d,d+k+1,ss)-d;
        int l = 0,r = k+1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(d[mid] > ss) r = mid;
            else    l = mid+1;
        }
        l--;
        long long tt = a[i]*(n-c[l]);
        ans = min(ans,tt);
    }
    printf("%I64d\n",ans);
    return 0;
}
