#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct line
{
    int to,w;
    line(int a,int b):to(a),w(b){}
    friend bool operator<(line X,line Y)
    {
        return X.w > Y.w;
    }
};

int n,m,dis[1005],vis[1005];
vector<line> v[1005];

int prim()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    int ans = 0,cnt = 0;
    priority_queue<line> q;
    q.push(line(1,0));
    int endd = n+m;
    while(cnt <= endd && !q.empty())
    {
        while(!q.empty() && vis[q.top().to])    q.pop();
        ans += q.top().w;
        int now = q.top().to;
        vis[now] = 1;
        cnt++;
        for(int i = 0;i < v[now].size();i++)
        {
            if(vis[v[now][i].to])   continue;
            if(dis[v[now][i].to] <= v[now][i].w)   continue;
            dis[v[now][i].to] = v[now][i].w;
            q.push(line(v[now][i].to,v[now][i].w));
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) v[i].clear();
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(line(b,c));
        v[b].push_back(line(a,c));
    }
    printf("%d\n",prim());
    return 0;
}
