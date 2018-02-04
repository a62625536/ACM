#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define N 4005
using namespace std;

struct edge
{
    int u,v,next;
    long long cap;
}e[1600005];
long long n,m,cnt,gmin[1005],gmax[1005],dmax[370],sum[1005],head[N],dep[N],gap[N],cur[N],st[N],que[N];

void addedge(int u,int v,long long cap)
{
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].cap = cap;
    e[cnt].next = head[u];
    head[u] = cnt++;
    e[cnt].u = v;
    e[cnt].v = u;
    e[cnt].cap = 0;
    e[cnt].next = head[v];
    head[v] = cnt++;
}
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int que[N];
    int front,rear;
    front=rear=0;
    dep[end]=0;
    que[rear++]=end;
    while(front!=rear)
    {
        int u=que[front++];
        if(front==N)front=0;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].v;
            if(e[i].cap!=0||dep[v]!=-1)continue;
            que[rear++]=v;
            if(rear>=N)rear=0;
            dep[v]=dep[u]+1;
            ++gap[dep[v]];
        }
    }
}
int isap(int start,int end,int n)
{
    int res=0;
    BFS(start,end);
    int cur[N];
    int S[N];
    int top=0;
    memcpy(cur,head,sizeof(head));
    int u=start;
    int i;
    while(dep[start]<n)
    {
        if(u==end)
        {
            int temp=INF;
            int inser;
            for(i=0;i<top;i++)
              if(temp>e[S[i]].cap)
              {
                  temp=e[S[i]].cap;
                  inser=i;
              }
            for(i=0;i<top;i++)
            {
                e[S[i]].cap-=temp;
                e[S[i]^1].cap+=temp;
            }
            res+=temp;
            top=inser;
            u=e[S[top]].u;
        }
        if(u!=end&&gap[dep[u]-1]==0)//出现断层，无增广路
           break;
        for(i=cur[u];i!=-1;i=e[i].next)
           if(e[i].cap!=0&&dep[u]==dep[e[i].v]+1)
             break;
        if(i!=-1)
        {
            cur[u]=i;
            S[top++]=i;
            u=e[i].v;
        }
        else
        {
            int min=n;
            for(i=head[u];i!=-1;i=e[i].next)
            {
                if(e[i].cap==0)continue;
                if(min>dep[e[i].v])
                {
                    min=dep[e[i].v];
                    cur[u]=i;
                }
            }
            --gap[dep[u]];
            dep[u]=min+1;
            ++gap[dep[u]];
            if(u!=start)u=e[S[--top]].u;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin >> n >> m)
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
        memset(sum,0,sizeof(sum));
        int flag = 1;
        for(int i = 0;i < m;i++)    cin >> gmin[i] >> gmax[i];
        long long has = 0;
        for(int i = 1;i <= n;i++)
        {
            int t;
            cin >> t >> dmax[i];
            while(t--)
            {
                int x,y,z;
                cin >> x >> y >> z;
                has += y;
                sum[x] += y;
                gmin[x] -= y;
                gmax[x] -= y;
                dmax[i] -= y;
                addedge(i,500+x,z-y);
                addedge(2100+i,2600+x,z-y);
            }
            if(dmax[i] < 0) flag = 0;
            addedge(0,i,dmax[i]);
            addedge(2100,2100+i,dmax[i]);
        }
        long long summ = 0;
        for(int i = 0;i < m;i++)
        {
            if(gmax[i] < 0) flag = 0;
        }
        for(int i = 0;i < m;i++)
        {
            if(gmin[i] > 0)
            {
                addedge(500+i,2000,gmin[i]);
                summ += gmin[i];
            }
            addedge(2600+i,4000,gmax[i]);
        }
        if(flag == 0 || isap(0,2000,n+m+2) != summ)  cout << "orz_GMH" << endl;
        else    cout << isap(2100,4000,n+m+2)+has << endl;
    }
    return 0;
}
