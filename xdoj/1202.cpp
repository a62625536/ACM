#include<bits/stdc++.h>
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

vector<xx> v[16005];
int n,m,r,h[105][105];
long long dis[16005];
bool vis[16005],has[105];

void add(int a,int b,int x)
{
    v[a].push_back(xx(b,x));
    v[b].push_back(xx(a,x));
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
            int tt = v[now][i].to,ww = v[now][i].w;
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
    int T;
    cin >> T;
    while(T--)
    {
        for(int i = 1;i <= 16000;i++)   v[i].clear();
        cin >> n >> m >> r;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)   cin >> h[i][j];
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(i+1 <= n)    add(105*i+j,105*i+j+105,2*(h[i][j]+h[i+1][j]));
                if(j+1 <= m)    add(105*i+j,105*i+j+1,2*(h[i][j]+h[i][j+1]));
            }
        }
        for(int k = 1;k <= r;k++)
        {
            memset(has,0,sizeof(has));
            int ax,ay,bx,by,t,kk;
            cin >> ax >> ay >> bx >> by >> t >> kk;
            for(int i = ax;i <= bx;i++)
            {
                for(int j = ay;j <= by;j++)
                {
                    add(11000+105*k+h[i][j],105*i+j,t);
                    v[12500+105*k+h[i][j]].push_back(xx(105*i+j,0));
                    v[105*i+j].push_back(xx(14000+105*k+h[i][j],0));
                    has[h[i][j]] = 1;
                }
            }
            for(int i = 0;i <= 100;i++)
            {
                if(!has[i]) continue;
                for(int j = i+1;j <= min(i+kk,100);j++)
                {
                    if(!has[j]) continue;
                    add(12500+105*k+i,14000+105*k+j,2*t);
                    add(14000+105*k+i,12500+105*k+j,2*t);
                }
            }
        }
        int sx,sy,ox,oy;
        cin >> sx >> sy >> ox >> oy;
        dij(105*sx+sy);
        cout << dis[105*ox+oy]/2 << endl;
    }
}
