#include<bits/stdc++.h>
using namespace std;

struct xxx
{
    int x,y,z;
    xxx(int xx,int yy,int zz):x(xx),y(yy),z(zz){};
};
int n,m,l,t,cnt,a[1300][130][65],vis[1300][130][65];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

void bfs(int x,int y,int z)
{
    vis[x][y][z] = 1;
    queue<xxx> q;
    q.push(xxx(x,y,z));
    while(!q.empty())
    {
        int x = q.front().x,y = q.front().y,z = q.front().z;
        q.pop();
        for(int i = 0;i < 6;i++)
        {
            int xx = x+dx[i],yy = y+dy[i],zz = z+dz[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m || zz < 1 || zz > l)    continue;
            if(vis[xx][yy][zz] || a[xx][yy][zz] == 0)   continue;
            vis[xx][yy][zz] = 1;
            q.push(xxx(xx,yy,zz));
            cnt++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> l >> t;
    for(int k = 1;k <= l;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)   cin >> a[i][j][k];
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            for(int k = 1;k <= l;k++)
            {
                if(vis[i][j][k] || a[i][j][k] == 0)    continue;
                cnt = 1;
                bfs(i,j,k);
                if(cnt >= t)    ans += cnt;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
