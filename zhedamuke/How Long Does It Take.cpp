#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;

struct line
{
    int to,time;
}l;
vector<struct line> v[105];
queue<int> q;
int n,m,indegree[105] = {0},timee[105] = {0};

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        int x;
        scanf("%d%d%d",&x,&l.to,&l.time);
        indegree[l.to]++;
        v[x].push_back(l);
    }
    int cnt = 0,ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            cnt++;
        }
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0;i < v[now].size();i++)
        {
            int to = v[now][i].to;
            int t = timee[now]+v[now][i].time;
            timee[to] = max(t,timee[to]);
            ans = max(ans,timee[to]);
            if(--indegree[to] == 0)
            {
                q.push(to);
                cnt++;
            }
        }
    }
    if(cnt < n) printf("Impossible\n");
    else    printf("%d\n",ans);
    return 0;
}
