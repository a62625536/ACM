#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,a[100005],b[100005];

int main()
{
    scanf("%d",&n);
    int l = 0,r = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        l += a[i];
        r += b[i];
    }
    int ans = 0,maxx = abs(l-r);
    for(int i = 1;i <= n;i++)
    {
        int ll = l-a[i]+b[i],rr = r-b[i]+a[i];
        if(abs(ll-rr) > maxx)
        {
            ans = i;
            maxx = abs(ll-rr);
        }
    }
    printf("%d\n",ans);
    return 0;
}
