#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct node
{
    int pos,cost;
    node(int a,int b):pos(a),cost(b){};
    friend bool operator <(node x,node y)
    {
        return x.cost > y.cost;
    }
};
struct edge
{
    int to,cost;
    edge(int a,int b):to(a),cost(b){};
};

int n,m,s[505],dis[505],sum[505],sta,en,vis[505];
vector<edge> v[505];

void dij()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(sum,0,sizeof(sum));
    dis[sta] = 0;
    sum[sta] = s[sta];
    priority_queue<node> q;
    q.push(node(sta,0));
    while(!q.empty())
    {
        int now = q.top().pos;
        q.pop();
        if(vis[now])    continue;
        vis[now] = 1;
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i].to,c = v[now][i].cost;
            if(!vis[t] && dis[t] > dis[now]+c)
            {
                dis[t] = dis[now]+c;
                sum[t] = sum[now]+s[t];
                q.push(node(t,dis[t]));
            }
            else if(dis[t] == dis[now]+c)
            {
                sum[t] = max(sum[t],sum[now]+s[t]);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&sta,&en);
    for(int i = 0;i < n;i++)    scanf("%d",&s[i]);
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(edge(b,c));
        v[b].push_back(edge(a,c));
    }
    dij();
    printf("%d %d\n",dis[en],sum[en]);
    return 0;
}
