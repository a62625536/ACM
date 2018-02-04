#include<bits/stdc++.h>
using namespace std;

int n,m,s,e,vis[505],dis[505],ti[505],pre[505];
vector<int> ans1,ans2;
struct edge
{
    int to,w,t;
    edge(int a,int b,int c):to(a),w(b),t(c){};
    friend bool operator <(edge x,edge y)
    {
        return x.w > y.w;
    }
};
vector<edge> v[1015];
struct cmp1
{
    bool operator()(edge x,edge y)
    {
        if(x.w != y.w)  return x.w > y.w;
        return x.t > y.t;
    }
};

struct cmp2
{
    bool operator()(edge x,edge y)
    {
        if(x.t != y.t)  return x.t > y.t;
        return x.w > y.w;
    }
};

void dij1()
{
    priority_queue< edge,vector<edge>,cmp1 > q;
    memset(dis,0x3f,sizeof(dis));
    memset(ti,0,sizeof(ti));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    ti[s] = 1;
    q.push(edge(s,0,0));
    while(!q.empty())
    {
        int now = q.top().to;
        q.pop();
        if(vis[now])    continue;
        vis[now] = 1;
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i].to,w = v[now][i].w;
            if(vis[t])  continue;
            if(dis[now]+w < dis[t])
            {
                dis[t] = dis[now]+w;
                ti[t] = ti[now]+1;
                q.push(edge(t,dis[t],ti[t]));
                pre[t] = now;
            }
            else if(dis[now]+w == dis[t] && ti[now]+1 < ti[t])
            {
                ti[t] = ti[now]+1;
                q.push(edge(t,dis[t],ti[t]));
                pre[t] = now;
            }
        }
    }
}

void dij2()
{
    priority_queue< edge,vector<edge>,cmp2 > q;
    memset(ti,0x3f,sizeof(ti));
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    ti[s] = 0;
    dis[s] = 0;
    q.push(edge(s,0,0));
    while(!q.empty())
    {
        int now = q.top().to;
        q.pop();
        if(vis[now])    continue;
        vis[now] = 1;
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i].to,w = v[now][i].w,tt = v[now][i].t;
            if(vis[t])  continue;
            if(ti[now]+tt < ti[t])
            {
                dis[t] = dis[now]+w;
                ti[t] = ti[now]+tt;
                q.push(edge(t,dis[t],ti[t]));
                pre[t] = now;
            }
            else if(ti[now]+tt == ti[t] && dis[now]+w < dis[t])
            {
                dis[t] = dis[now]+w;
                q.push(edge(t,dis[t],ti[t]));
                pre[t] = now;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        int x,y,a,b,c;
        cin >> x >> y >> a >> b >> c;
        v[x].push_back(edge(y,b,c));
        if(!a)  v[y].push_back(edge(x,b,c));
    }
    cin >> s >> e;
    dij1();
    int mindis = dis[e];
    int now = e;
    while(now != s)
    {
        ans1.push_back(now);
        now = pre[now];
    }
    dij2();
    int mint = ti[e];
    now = e;
    while(now != s)
    {
        ans2.push_back(now);
        now = pre[now];
    }
    if(ans1 == ans2)
    {
        cout << "Time = " << mint << "; Distance = " << mindis << ": " << s;
        for(int i = ans1.size()-1;i >= 0;i--)  cout << " => " << ans1[i];
        cout << endl;
    }
    else
    {
        cout << "Time = " << mint << ": " << s;
        for(int i = ans2.size()-1;i >= 0;i--)  cout << " => " << ans2[i];
        cout << endl;
        cout << "Distance = " << mindis << ": " << s;
        for(int i = ans1.size()-1;i >= 0;i--)  cout << " => " << ans1[i];
        cout << endl;
    }
    return 0;
}
