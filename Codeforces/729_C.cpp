#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k,s,t,c[200005],v[200005],g[200005];

bool f(int x)
{
    int tt = 0;
    for(int i = 1;i <= k+1;i++)
    {
        int temp = g[i]-g[i-1];
        if(x < temp)    return 0;
        if(x >= temp*2) tt += temp;
        else    tt += 3*temp-x;
    }
    if(tt > t)  return 0;
    return 1;
}
int main()
{
    scanf("%d%d%d%d",&n,&k,&s,&t);
    for(int i = 1;i <= n;i++)   scanf("%d%d",&c[i],&v[i]);
    for(int i = 1;i <= k;i++)   scanf("%d",&g[i]);
    sort(g+1,g+1+k);
    g[k+1] = s;
    g[0] = 0;
    int l = 0,r = 1e9+1;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(f(mid))  r = mid;
        else    l = mid+1;
    }
    int ans = 1e9+1;
    for(int i = 1;i <= n;i++)
    {
        if(v[i] >= l)   ans = min(ans,c[i]);
    }
    if(ans == 1e9+1)    printf("-1\n");
    else    printf("%d\n",ans);
    return 0;
}
