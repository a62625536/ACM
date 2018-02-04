#include<bits/stdc++.h>
#define N 200005
using namespace std;

int n,m,cnt = 0,tot = 0,a[N],p[N],fa[N],f[N*2],rmq[N*2];
int tree[N],lson[N*30],rson[N*30],c[N*30];
vector<int> v[N];

struct ST
{
    int mm[2*N],dp[2*N][20];
    void init(int n)
    {
        mm[0] = -1;
        for(int i = 1;i <= n;i++)
        {
            mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
            dp[i][0] = i;
        }
        for(int j = 1;j <= mm[n];j++)
        {
            for(int i = 1;i+(1<<j)-1 <= n;i++)  dp[i][j] = rmq[dp[i][j-1]] < rmq[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
        }
    }
    int query(int a,int b)
    {
        if(a > b)   swap(a,b);
        int k = mm[b-a+1];
        return rmq[dp[a][k]] <= rmq[dp[b-(1<<k)+1][k]]?dp[a][k]:dp[b-(1<<k)+1][k];
    }
}st;

void dfs(int now,int pre,int dep)
{
    f[++cnt] = now;
    rmq[cnt] = dep;
    p[now] = cnt;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        dfs(t,now,dep+1);
        f[++cnt] = now;
        rmq[cnt] = dep;
    }
}

void initlca(int root,int n)
{
    cnt = 0;
    dfs(root,root,0);
    st.init(2*n-1);
}

int querylca(int x,int y)
{
    return f[st.query(p[x],p[y])];
}

void build(int &now,int l,int r)
{
    now = tot++;
    c[now] = 0;
    if(l == r)  return;
    int mid = (l+r)/2;
    build(lson[now],l,mid);
    build(rson[now],mid+1,r);
}

void update(int &now,int last,int l,int r,int pos,int x)
{
    now = tot++;
    lson[now] = lson[last];
    rson[now] = rson[last];
    c[now] = c[last]+x;
    if(l == r)  return;
    int mid = (l+r)/2;
    if(pos <= mid)  update(lson[now],lson[last],l,mid,pos,x);
    else    update(rson[now],rson[last],mid+1,r,pos,x);
}

int query(int x,int y,int lca,int p,int l,int r)
{
    if(l == r)  return l;
    int t = c[lson[x]]+c[lson[y]]-c[lson[lca]]-c[lson[p]],mid = (l+r)/2;
    if(t < mid-l+1) return query(lson[x],lson[y],lson[lca],lson[p],l,mid);
    return query(rson[x],rson[y],rson[lca],rson[p],mid+1,r);
}

void dfsbuild(int now,int pre)
{
    fa[now] = pre;
    update(tree[now],tree[pre],0,n-1,a[now],1);
    for(int t : v[now])
    {
        if(t == pre)    continue;
        dfsbuild(t,now);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i < n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    initlca(1,n);
    build(tree[0],0,n-1);
    dfsbuild(1,0);
    scanf("%d",&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int lca = querylca(x,y);
        printf("%d\n",query(tree[x],tree[y],tree[lca],tree[fa[lca]],0,n-1));
    }
    return 0;
}
