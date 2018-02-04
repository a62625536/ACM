#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n,m,from[1005],to[1005];
vector<int> v[1005];

int dfs(int s,int t)
{
    int ans = 1;
    for(int i = 0;i < v[s].size();i++)
    {
        if(v[s][i] == t)    continue;
        ans += dfs(v[s][i],s);
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)   v[i].clear();
        for(int i = 1;i < n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            from[i] = a;
            to[i] = b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i = 1;i <= m;i++)
        {
            int x;
            scanf("%d",&x);
            int t = dfs(to[x],from[x]);
            printf("%d\n",t*(n-t));
        }
    }
    return 0;
}
