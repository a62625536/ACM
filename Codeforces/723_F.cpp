#include<bits/stdc++.h>
using namespace std;

struct xx
{
    int x,y;
    xx(int a,int b):x(a),y(b){};
};
int n,m,x,y,dx,dy,cnt = 0,a[200005] = {0},b[200005] = {0},vis[200005] = {0};
vector<int> v[200005];
vector<xx> ans;

void dfs(int now)
{
    vis[now] = 1;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == x)  a[cnt] = now;
        else if(t == y) b[cnt] = now;
        else if(!vis[t])
        {
            ans.push_back(xx(now,t));
            dfs(t);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin >> x >> y >> dx >> dy;
    for(int i = 1;i <= n;i++)
    {
        if(vis[i] || i == x || i == y)  continue;
        ++cnt;
        dfs(i);
    }
    int z = 0;
    for(int i = 1;i <= cnt;i++)
    {
        if(a[i] == 0)
        {
            ans.push_back(xx(b[i],y));
            dy--;
        }
        else if(b[i] == 0)
        {
            ans.push_back(xx(a[i],x));
            dx--;
        }
        else z++;
    }
    if(dx < 1 || dy < 1 || dx+dy-1 < z)
    {
        cout << "No" << endl;
        return 0;
    }
    if(z == 0)  ans.push_back(xx(x,y));
    else
    {
        int flag = 0;
        for(int i = 1;i <= cnt;i++)
        {
            if(a[i] == 0 || b[i] == 0)  continue;
            if(flag)
            {
                if(dx)
                {
                    ans.push_back(xx(a[i],x));
                    dx--;
                }
                else
                {
                    ans.push_back(xx(b[i],y));
                    dy--;
                }
            }
            else
            {
                flag = 1;
                ans.push_back(xx(a[i],x));
                dx--;
                ans.push_back(xx(b[i],y));
                dy--;
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 0;i < ans.size();i++) cout << ans[i].x << " " << ans[i].y << endl;
    return 0;
}
