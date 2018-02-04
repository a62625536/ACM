#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int point[100005];
struct line
{
    int v,u,w;
}l[1000005];
int n,pre[100005];

bool cmp(line x,line y)
{
    return x.w < y.w;
}

int findd(int x)
{
    int root = x;
    while(root != pre[root])    root = pre[root];
    int temp;
    while(x != pre[x])
    {
        temp = pre[x];
        pre[x] = root;
        x = temp;
    }
    return root;
}

int main()
{
    while(~scanf("%d",&n))
    {
        long long ans = 0;
        for(int i = 1;i < n;i++)    scanf("%d%d%d",&l[i].u,&l[i].v,&l[i].w);
        sort(l+1,l+n,cmp);
        for(int i = 1;i <= n;i++)
        {
            pre[i] = i;
            point[i] = 1;
        }
        for(int i = 1;i < n;i++)
        {
            int x = findd(l[i].u),y = findd(l[i].v);
            ans += (long long)point[x]*point[y]*l[i].w;
            pre[x] = y;
            point[y] += point[x];
        }
        for(int i = 1;i <= n;i++)
        {
            pre[i] = i;
            point[i] = 1;
        }
        for(int i = n-1;i >= 1;i--)
        {
            int x = findd(l[i].u),y = findd(l[i].v);
            ans -= (long long)point[x]*point[y]*l[i].w;
            pre[x] = y;
            point[y] += point[x];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
