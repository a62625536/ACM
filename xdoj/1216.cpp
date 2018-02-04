#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,m,cnt,l[N],r[N],pos[N];
int a[N];
vector<int> v[N];

void dfs(int now,int pre)
{
    l[now] = ++cnt;
    pos[cnt] = now;
    for(int i = 0;i < v[now].size();i++)
    {
        int  t = v[now][i];
        if(t == pre)    continue;
        dfs(t,now);
    }
    r[now] = cnt;
}

int tree[20][N],sorted[N],toleft[20][N];

void build(int l,int r,int dep)
{
    if(l == r)return;
    int mid = (l+r)/2,same = mid-l+1;
    for(int i = l;i <= r;i++)
    {
        if(tree[dep][i] < sorted[mid])  same--;
    }
    int lpos = l,rpos = mid+1;
    for(int i = l;i <= r;i++)
    {
        if(tree[dep][i] < sorted[mid])  tree[dep+1][lpos++] = tree[dep][i];
        else if(tree[dep][i] == sorted[mid] && same > 0)
        {
            tree[dep+1][lpos++] = tree[dep][i];
            same--;
        }
        else    tree[dep+1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l-1]+lpos-l;
    }
    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}

int query(int l,int r,int ql,int qr,int dep,int k)
{
    if(ql == qr)    return tree[dep][ql];
    int mid = (l+r)/2,cnt = toleft[dep][qr]-toleft[dep][ql-1];
    if(cnt >= k)
    {
        int ll = l+toleft[dep][ql-1]-toleft[dep][l-1],rr = ll+cnt-1;
        return query(l,mid,ll,rr,dep+1,k);
    }
    else
    {
        int rr = qr+toleft[dep][r]-toleft[dep][qr],ll = rr-(qr-ql-cnt);
        return query(mid+1,r,ll,rr,dep+1,k-cnt);
    }
}


int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
        for(int i = 1;i <= n;i++)   v[i].clear();
        cnt = 0;
        for(int i = 1;i < n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,-1);
        for(int i = 1;i <= n;i++)  sorted[i] = tree[0][i] = a[pos[i]];
        sort(sorted+1,sorted+n+1);
        build(1,n,0);
        scanf("%d",&m);
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query(1,n,l[x],r[x],0,y));
        }
    }
    return 0;
}
