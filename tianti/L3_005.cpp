#include<bits/stdc++.h>
using namespace std;

int n,m,k,d,vis[1015],dis[1015];
struct edge
{
    int to,w;
    edge(int a,int b):to(a),w(b){};
    friend bool operator <(edge x,edge y)
    {
        return x.w > y.w;
    }
};
vector<edge> v[1015];
struct anss
{
    int sum,id,dis;
    friend bool operator <(anss x,anss y)
    {
        if(x.dis != y.dis)  return x.dis > y.dis;
        if(x.sum != y.sum)  return x.sum < y.sum;
        return x.id < y.id;
    }
}ans[15];

void dij(int start)
{
    priority_queue<edge> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[start] = 0;
    q.push(edge(start,0));
    while(!q.empty())
    {
        int now = q.top().to;
        q.pop();
        if(vis[now])    continue;
        vis[now] = 1;
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i].to,w = v[now][i].w;
            if(!vis[t] && dis[now]+w < dis[t])
            {
                dis[t] = dis[now]+w;
                q.push(edge(t,dis[t]));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    scanf("%d%d%d%d",&n,&m,&k,&d);
    for(int i = 1;i <= k;i++)
    {
        char s1[50],s2[50];
        int w,x,y;
        scanf("%s%s%d",s1,s2,&w);
        if(s1[0] == 'G')
        {
            sscanf(s1,"G%d",&x);
            x += n;
        }
        else    sscanf(s1,"%d",&x);
        if(s2[0] == 'G')
        {
            sscanf(s2,"G%d",&y);
            y += n;
        }
        else    sscanf(s2,"%d",&y);
        v[x].push_back(edge(y,w));
        v[y].push_back(edge(x,w));
    }
    int cnt = 0;
    for(int i = n+1;i <= n+m;i++)
    {
        dij(i);
        int sum = 0,minn = 1e9,flag = 0;
        for(int j = 1;j <= n;j++)
        {
            if(dis[j] > d)
            {
                flag = 1;
                break;
            }
            sum += dis[j];
            minn = min(minn,dis[j]);
        }
        if(flag)    continue;
        cnt++;
        ans[cnt].dis = minn;
        ans[cnt].sum = sum;
        ans[cnt].id = i-n;
    }
    if(cnt == 0)    cout << "No Solution" << endl;
    else
    {
        sort(ans+1,ans+1+cnt);
        printf("G%d\n%.1f %.1f\n",ans[1].id,(double)ans[1].dis,(double)ans[1].sum/n);
    }
    return 0;
}
