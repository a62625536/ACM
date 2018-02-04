#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,m,vis[1005][1005][2] = {0},x1,Y1,flag = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
string a[1005];

void dfs(int x,int y,int d,int cnt)
{
    if(cnt > 2) return;
    if(flag)    return;
    if(a[x][y] == 'T')  flag = 1;
    if(d != -1) vis[x][y][d] = 1;
    for(int i = 0;i < 4;i++)
    {
        if((i+2)%4 == d)  continue;
        int xx = x+dx[i],yy = y+dy[i];
        if(xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] == '*')  continue;
        if(vis[xx][yy][i])  continue;
        dfs(xx,yy,i,cnt+(i != d));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        a[i] = " "+a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] == 'S')  x1 = i,Y1 = j;
        }
    }
    dfs(x1,Y1,-1,-1);
    if(flag)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
