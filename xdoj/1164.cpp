#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int a[10000005],pre[10000005] = {0},sum[10000005] = {0},n,u,v;
bool vis[10000005] = {0};

long long dfs(int pos)
{
    if(vis[pos])    return 0;
    vis[pos] = 1;
    if(!pre[pos])
    {
        sum[pos] -= a[pos];
        return abs(sum[pos]);
    }
    long long t = dfs(pre[pos]);
    a[pos] += sum[pre[pos]];
    t += abs(a[pos]);
    sum[pos] += sum[pre[pos]]-a[pos];
    return t;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i < n;i++)
    {
        scanf("%d%d",&u,&v);
        pre[v] = u;
    }
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    long long ans = 0;
    for(int i = 1;i <= n;i++)   ans += dfs(i);
    printf("%lld\n",ans);
    return 0;
}
