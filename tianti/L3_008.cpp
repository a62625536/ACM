#include<bits/stdc++.h>
using namespace std;

int n,m,k,vis[10005],ans[10005];
vector<int> v[10005];

int dfs(int x,int minn)
{
    vis[x] = 1;
    minn = min(minn,x);
    for(int i = 0;i < v[x].size();i++)
    {
        if(!vis[v[x][i]])minn = min(minn,dfs(v[x][i],minn));
    }
    return minn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    while(k--)
    {
        int x;
        cin >> x;
        if(v[x].size() == 0)    cout << 0 << endl;
        else
        {
            queue<int> q;
            memset(vis,0,sizeof(vis));
            memset(ans,0,sizeof(ans));
            vis[x] = 1;
            q.push(x);
            while(!q.empty())
            {
                int now = q.front();
                q.pop();
                for(int i = 0;i < v[now].size();i++)
                {
                    int t = v[now][i];
                    if(vis[t])  continue;
                    vis[t] = 1;
                    ans[t] = ans[now]+1;
                    q.push(t);
                }
            }
            int x = 0,num;
            for(int i = 1;i <= n;i++)
            {
                if(ans[i] > x)
                {
                    num = i;
                    x = ans[i];
                }
            }
            cout << num << endl;
        }
    }
    return 0;
}
