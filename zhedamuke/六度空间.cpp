#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
vector<int> v[10005];
queue<int> q;
int visit[10005],n,m;

int countt(int x)
{
    while(!q.empty())   q.pop();
    memset(visit,0,sizeof(visit));
    int cnt = 1,last = x,level = 0,tail;
    q.push(x);
    visit[x] = 1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0;i < v[now].size();i++)
        {
            if(visit[v[now][i]])    continue;
            visit[v[now][i]] = 1;
            cnt++;
            q.push(v[now][i]);
            tail = v[now][i];
        }
        if(now == last)
        {
            level++;
            last = tail;
        }
        if(level == 6)  break;
    }
    return cnt;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1;i <= n;i++)
    {
        int num = countt(i);
        printf("%d: %.2f%%\n",i,(double)num/n*100);
    }
    return 0;
}
