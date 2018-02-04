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
struct line2
{
    int last,time;
}ll;
vector<struct line> v[105];
vector<struct line2> v2[105];
queue<int> q;
int n,m,indegree[105] = {0},timee[105] = {0},outdegree[105] = {0},timee2[105];

int main()
{
    memset(timee2,0x3f,sizeof(timee2));
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        int x;
        scanf("%d%d%d",&x,&l.to,&l.time);
        indegree[l.to]++;
        v[x].push_back(l);
        ll.last = x;
        ll.time = l.time;
        outdegree[x]++;
        v2[l.to].push_back(ll);
    }
    int cnt = 0,ans = 0;
    for(int i = 1;i <= n;i++)
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
    if(cnt < n)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n",ans);
    while(!q.empty())   q.pop();
    for(int i = 1;i <= n;i++)
    {
        if(outdegree[i] == 0)
        {
            q.push(i);
            timee2[i] = ans;
        }
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0;i < v2[now].size();i++)
        {
            int last = v2[now][i].last;
            int t = timee2[now]-v2[now][i].time;
            timee2[last] = min(timee2[last],t);
            if(--outdegree[last] == 0)  q.push(last);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = v[i].size()-1;j >= 0;j--)
        {
            if(timee2[v[i][j].to]-timee[i] == v[i][j].time)
            {
                printf("%d->%d\n",i,v[i][j].to);
            }
        }
    }
    return 0;
}
