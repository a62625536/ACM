#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

LL a[10005],b[10005];
int n,m,k;

int f(LL x)
{
    int ans = 0,now = m;
    for(int i = 1;i <= n;i++)
    {
        while(now)
        {
            if(a[i]*b[now] > x) now--;
            else    break;
        }
        ans += now;
    }
    return n*m-ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        k--;
        for(int i = 1;i <= n;i++)   scanf("%lld",&a[i]);
        for(int i = 1;i <= m;i++)   scanf("%lld",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        LL l = a[1]*b[1],r = a[n]*b[m];
        while(l < r)
        {
            LL mid = (l+r)/2;
            int t = f(mid);
            if(t <= k)   r = mid;
            else    l = mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
