#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

struct xx
{
    int to;
    long long w;
    xx(int a,long long b):to(a),w(b){};
    friend bool operator <(xx X,xx Y)
    {
        return X.w > Y.w;
    }
};
struct segtree
{
    int l,r,id;
}tree1[2000005],tree2[2000005];
vector<xx> v[2500005];
int n,m,s,cnt;
long long dis[2500005];
bool vis[2500005];

void build1(int pos,int l,int r)
{
    tree1[pos].l = l;
    tree1[pos].r = r;
    tree1[pos].id = ++cnt;
    for(int i = l;i <= r;i++)   v[cnt].push_back(xx(i,0));
    if(l == r)  return;
    int mid = (l+r)/2;
    build1(pos*2,l,mid);
    build1(pos*2+1,mid+1,r);
}

void build2(int pos,int l,int r)
{
    tree2[pos].l = l;
    tree2[pos].r = r;
    tree2[pos].id = ++cnt;
    for(int i = l;i <= r;i++)   v[i].push_back(xx(cnt,0));
    if(l == r)  return;
    int mid = (l+r)/2;
    build2(pos*2,l,mid);
    build2(pos*2+1,mid+1,r);
}

void update1(int pos,int l,int r,int id,long long w)
{
    if(l <= tree1[pos].l && tree1[pos].r <= r)
    {
        v[id].push_back(xx(tree1[pos].id,w));
        return;
    }
    int mid = (tree1[pos].l+tree1[pos].r)/2;
    if(l <= mid)    update1(pos*2,l,r,id,w);
    if(r > mid)     update1(pos*2+1,l,r,id,w);
}

void update2(int pos,int l,int r,int id,long long w)
{
    if(l <= tree2[pos].l && tree2[pos].r <= r)
    {
        v[tree2[pos].id].push_back(xx(id,w));
        return;
    }
    int mid = (tree2[pos].l+tree2[pos].r)/2;
    if(l <= mid)    update2(pos*2,l,r,id,w);
    if(r > mid)     update2(pos*2+1,l,r,id,w);
}

void dij(int beg)
{
    priority_queue<xx> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[beg] = 0;
    q.push(xx(beg,0));
    while(!q.empty())
    {
        int now = q.top().to;
        q.pop();
        if(vis[now])    continue;
        vis[now] = 1;
        for(int i = 0;i < v[now].size();i++)
        {
            int tt = v[now][i].to;
            long long ww = v[now][i].w;
            if(!vis[tt] && dis[now]+ww < dis[tt])
            {
                dis[tt] = dis[now]+ww;
                q.push(xx(tt,dis[tt]));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    cnt = n;
    build1(1,1,n);
    build2(1,1,n);
    while(m--)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int a,b,c;
            cin >> a >> b >> c;
            v[a].push_back(xx(b,c));
        }
        else
        {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            if(x == 2)  update1(1,b,c,a,d);
            else    update2(1,b,c,a,d);
        }
    }
    dij(s);
    for(int i = 1;i <= n;i++)
    {
        if(dis[i] == INF)    cout << -1 << " ";
        else    cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}
