#include<bits/stdc++.h>
using namespace std;

int n,m,vis[105][105],pre[105][105],ans[100005];
char dir[4] = {'U','D','L','R'};
string s[105];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
struct xxx
{
    int x,y;
    xxx(int a,int b):x(a),y(b){};
};

void bfs()
{
    queue<xxx> q;
    q.push(xxx(1,1));
    vis[1][1] = 1;
    while(!q.empty())
    {
        int x = q.front().x,y = q.front().y;
        q.pop();
        if(s[x][y] == 'F')  return;
        for(int i = 0;i < 4;i++)
        {
            int xx = x+dx[i],yy = y+dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m)    continue;
            if(s[xx][yy] == '*')    continue;
            if(vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            pre[xx][yy] = i;
            q.push(xxx(xx,yy));
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        s[i] = ' '+s[i];
    }
    bfs();
    int tx,ty;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i][j] == 'F')
            {
                tx = i;
                ty = j;
            }
        }
    }
    int x = tx,y = ty,cnt = 0;
    while(x != 1 || y != 1)
    {
        ans[++cnt] = pre[x][y];
        int xx = x,yy = y;
        x -= dx[pre[xx][yy]];
        y -= dy[pre[xx][yy]];
    }
    int nowx = 1+dx[ans[cnt]],nowy = 1+dy[ans[cnt]],now = cnt-1;
    cout << dir[ans[cnt]] << endl;
    while(cin >> x >> y && x != tx || y != ty)
    {
        if(nowx != x || nowy != y)
        {
            now++;
            nowx -= dx[ans[now]];
            nowy -= dy[ans[now]];
            if(ans[now] <= 1)   swap(dir[0],dir[1]);
            else    swap(dir[2],dir[3]);
        }
        nowx += dx[ans[now]];
        nowy += dy[ans[now]];
        cout << dir[ans[now--]] << endl;
    }
    return 0;
}
