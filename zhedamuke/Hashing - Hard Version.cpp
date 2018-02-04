#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct node
{
    int p,k;
    friend bool operator<(node a,node b)
    {
        return a.k > b.k;
    }
}g[1005];

int n,ans[1005],degree[1005],cnt = 0;
vector<int> v[1005];

void topsort()
{
    priority_queue<node> q;
    for(int i = 0;i < n;i++)
    {
        if(degree[i] == 0)  q.push(g[i]);
    }
    while(!q.empty())
    {
        ans[++cnt] = q.top().k;
        int now = q.top().p;
        q.pop();
        for(int i = 0;i < v[now].size();i++)
        {
            if(--degree[v[now][i]] == 0)    q.push(g[v[now][i]]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&g[i].k);
        if(g[i].k < 0)
        {
            degree[i] = -1;
            continue;
        }
        g[i].p = i;
        degree[i] = (i-g[i].k%n+n)%n;
        for(int j = 0;j < degree[i];j++)    v[(g[i].k%n+j+n)%n].push_back(i);
    }
    topsort();
    printf("%d",ans[1]);
    for(int i = 2;i <= cnt;i++) printf(" %d",ans[i]);
    printf("\n");
    return 0;
}
