#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,a[100005];
vector<int> v[100005];
long long ans[100005];

void dfs(int x,int pre)
{
    for(int i = 0;i < v[x].size();i++)
    {
        int t = v[x][i];
        if(t == pre)    continue;
        ans[t] = ans[x]+a[t];
        dfs(t,x);
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)   v[i].clear();
        memset(a,0,sizeof(a));
        for(int i = 1;i < n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x] = y;
        }
        memset(ans,0,sizeof(ans));
        for(int i = 1;i <= n;i++)   ans[i] = a[i];
        dfs(1,-1);
        int t = 0;
        long long maxx = 0;
        for(int i = 1;i <= n;i++)
        {
            if(ans[i] > maxx)
            {
                t = i;
                maxx = ans[i];
            }
        }
        memset(ans,0,sizeof(ans));
        for(int i = 1;i <= n;i++)   ans[i] = a[i];
        dfs(t,-1);
        maxx = 0;
        for(int i = 1;i <= n;i++)
        {
            maxx = max(ans[i],maxx);
        }
        printf("%lld\n",maxx);
    }
    return 0;
}
