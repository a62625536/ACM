#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,dir[4][2] = {-1,0,0,-1,1,0,0,1},ans[35][2];
vector<int> v[35];

void dfs(int now,int pre,int sta,int l,int x,int y)
{
    ans[now][0] = x;
    ans[now][1] = y;
    int ii = 0;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        if(ii == sta)   ii++;
        int xx = x+dir[ii][0]*l,yy = y+dir[ii][1]*l;
        dfs(t,now,(ii+2)%4,l>>1,xx,yy);
        ii++;
    }
}

int main()
{
    cin >> n;
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1;i <= n;i++)
    {
        if(v[i].size() > 4)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    dfs(1,0,-1,1<<n,0,0);
    cout << "YES" << endl;
    for(int i = 1;i <= n;i++)   cout << ans[i][0] << " " << ans[i][1] << endl;
    return 0;
}
