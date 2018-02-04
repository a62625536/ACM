#include<bits/stdc++.h>
using namespace std;

struct yyy
{
    int x,y,w,id;
    friend bool operator<(yyy a,yyy b)
    {
        return a.w > b.w;
    }
}a[1000005];
int n,m,mp[1005][1005],pre[1000005],num[1000005] = {0};
long long k,sum[1000005] = {0};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
struct xxx
{
    int x,y;
    xxx(int a,int b):x(a),y(b){};
};
int vis[1005][1005] = {0};

int findd(int x)
{
    return pre[x] == x?x:pre[x] = findd(pre[x]);
}

void join(int x,int y)
{
    int yyy = findd(x),yy = findd(y);
    if(yyy != yy)
    {
        pre[yyy] = yy;
        sum[yy] += sum[yyy];
        num[yy] += num[yyy];
    }
}
void solve(int &ansx,int &ansy)
{
    for(int i = 1;i <= n*m;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            int x = a[i].x+dx[j],y = a[i].y+dy[j];
            if(x < 1 || x > n || y < 1 || y > m)    continue;
            if(mp[x][y] < a[i].w)   continue;
            join(a[i].id,(x-1)*n+y);
        }
        int t = findd(a[i].id);
        if(k%a[i].w)    continue;
        if((long long)num[t]*a[i].w >= k)
        {
            ansx = a[i].x;
            ansy = a[i].y;
            return;
        }
    }
    ansx = -1;
}

int main()
{
    cin >> n >> m >> k;
    int cnt = 0;
    for(int i = 1;i <= n*m;i++)   pre[i] = i;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> mp[i][j];
            a[++cnt].x = i;
            a[cnt].y = j;
            a[cnt].w = mp[i][j];
            a[cnt].id = cnt;
            sum[cnt] = mp[i][j];
            num[cnt] = 1;
        }
    }
    sort(a+1,a+1+cnt);
    int x,y;
    solve(x,y);
    if(x == -1) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        queue<xxx> q;
        q.push(xxx(x,y));
        int t = mp[x][y];
        while(!q.empty())
        {
            int x = q.front().x,y = q.front().y;
            q.pop();
            if(vis[x][y])   continue;
            vis[x][y] = 1;
            k -= t;
            if(k == 0)  break;
            for(int i = 0;i < 4;i++)
            {
                int xx = x+dx[i],yy = y+dy[i];
                if(xx < 1 || xx > n || xx < 1 || yy > m)    continue;
                if(mp[xx][yy] < t || vis[xx][yy])   continue;
                q.push(xxx(xx,yy));
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)   cout << (vis[i][j]?t:0) << " ";
            cout << endl;
        }
    }
}
