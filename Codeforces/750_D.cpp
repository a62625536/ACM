#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,t[35],a[305][305] = {0},vis[35][305][305][8] = {0};
int dir[8][2] = {-1,0,-1,-1,0,-1,1,-1,1,0,1,1,0,1,-1,1};

void dfs(int now,int x,int y,int d)
{
    if(vis[now][x][y][d])   return;
    vis[now][x][y][d] = 1;
    a[x][y] = 1;
    for(int i = 1;i < t[now];i++)
    {
        x += dir[d][0];
        y += dir[d][1];
        a[x][y] = 1;
    }
    if(++now > n)    return;
    int dd = (d+1)%8;
    dfs(now,x+dir[dd][0],y+dir[dd][1],dd);
    dd = (d+7)%8;
    dfs(now,x+dir[dd][0],y+dir[dd][1],dd);
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> t[i];
    int ans = 0;
    dfs(1,150,150,0);
    for(int i = 0;i <= 300;i++)
    {
        for(int j = 0;j <= 300;j++)
        {
            if(a[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
