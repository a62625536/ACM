#include<bits/stdc++.h>
using namespace std;

int n,cnt[2],a[2][7005],deg[2][7005],dp[2][7005],vis[2][7005] = {0};
struct xx
{
    int now,pos,sta;
    xx(int a,int b,int c):now(a),pos(b),sta(c){};
};

void bfs()
{
    queue<xx> q;
    dp[0][1] = -1;
    dp[1][1] = -1;
    q.push(xx(0,1,-1));
    q.push(xx(1,1,-1));
    while(!q.empty())
    {
        int now = q.front().now,pos = q.front().pos,sta = q.front().sta;
        q.pop();
        if(vis[now][pos])   continue;
        vis[now][pos] = 1;
        now = 1-now;
        if(sta == -1)
        {
            for(int i = 1;i <= cnt[now];i++)
            {
                int poss = pos-a[now][i]+n;
                if(poss > n)    poss -= n;
                if(vis[now][poss])  continue;
                dp[now][poss] = 1;
                q.push(xx(now,poss,1));
            }
        }
        else
        {
            for(int i = 1;i <= cnt[now];i++)
            {
                int poss = pos-a[now][i]+n;
                if(poss > n)    poss -= n;
                if(vis[now][poss])  continue;
                deg[now][poss]--;
                if(deg[now][poss] == 0)
                {
                    dp[now][poss] = 2;
                    q.push(xx(now,poss,-1));
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> cnt[0];
    for(int i = 1;i <= cnt[0];i++)  cin >> a[0][i];
    cin >> cnt[1];
    for(int i = 1;i <= cnt[1];i++)  cin >> a[1][i];
    for(int i = 1;i <= n;i++)
    {
        deg[0][i] = cnt[0];
        deg[1][i] = cnt[1];
    }
    bfs();
    for(int i = 0;i < 2;i++)
    {
        for(int j = 2;j <= n;j++)
        {
            if(!vis[i][j])  cout << "Loop ";
            else if(dp[i][j] == 1)  cout << "Win ";
            else cout << "Lose ";
        }
        cout << endl;
    }
    return 0;
}
