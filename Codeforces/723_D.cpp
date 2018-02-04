#include<bits/stdc++.h>
using namespace std;

int n,m,k,vis[55][55] = {0},ok,sum;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
string s[55];
struct xxx
{
    int x,y,sum;
    friend bool operator <(xxx a,xxx b)
    {
        return a.sum < b.sum;
    }
}a[2505];

void dfs1(int x,int y)
{
    if(vis[x][y])   return;
    vis[x][y] = 1;
    sum++;
    for(int i = 0;i < 4;i++)
    {
        int xx = x+dx[i],yy = y+dy[i];
        if(xx < 1 || xx > n || yy < 1 || yy > m)
        {
            ok = 0;
            continue;
        }
        if(s[xx][yy] == '*')    continue;
        dfs1(xx,yy);
    }
}

void dfs2(int x,int y)
{
    s[x][y] = '*';
    for(int i = 0;i < 4;i++)
    {
        int xx = x+dx[i],yy = y+dy[i];
        if(xx < 1 || xx > n || yy < 1 || yy > m || s[xx][yy] == '*')    continue;
        dfs2(xx,yy);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        s[i] = " "+s[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i][j] == '*' || vis[i][j])   continue;
            ok = 1;
            sum = 0;
            dfs1(i,j);
            if(ok)
            {
                a[++cnt].x = i;
                a[cnt].y = j;
                a[cnt].sum = sum;
            }
        }
    }
    sort(a+1,a+1+cnt);
    cnt -= k;
    int ans = 0;
    for(int i = 1;i <= cnt;i++)
    {
        ans += a[i].sum;
        dfs2(a[i].x,a[i].y);
    }
    cout << ans << endl;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)   cout << s[i][j];
        cout << endl;
    }
	return 0;
 }

