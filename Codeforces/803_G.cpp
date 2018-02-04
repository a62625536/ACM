#include<bits/stdc++.h>
using namespace std;

int n,k,q,cnt = 0,a[100005];
struct segtree
{
    int l,r,x,lazy;
    segtree *lson,*rson;
}*root;

struct ST
{
    int mm[100005],dp[100005][20];
    void init()
    {
        mm[0] = -1;
        for(int i = 1;i <= n;i++)
        {
            mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
            dp[i][0] = a[i];
        }
        for(int j = 1;j <= mm[n];j++)
        {
            for(int i = 1;i+(1<<j)-1 <= n;i++)  dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    int query(int a,int b)
    {
        if(a > b)   swap(a,b);
        int k = mm[b-a+1];
        return min(dp[a][k],dp[b-(1<<k)+1][k]);
    }
}st;

segtree *newnode(int l,int r)
{
    segtree *t = new segtree;
    t->l = l;
    t->r = r;
    t->lson = NULL;
    t->rson = NULL;
    t->lazy = 0;
    if(r-l+1 >= n)  t->x = st.query(1,n);
    else
    {
        l = (l-1)%n+1;
        r = (r-1)%n+1;
        if(l <= r)  t->x = st.query(l,r);
        else    t->x = min(st.query(1,r),st.query(l,n));
    }
    return t;
}

segtree *newlson(segtree *pos)
{
    int mid = (pos->l+pos->r)/2;
    return newnode(pos->l,mid);
}

segtree *newrson(segtree *pos)
{
    int mid = (pos->l+pos->r)/2;
    return newnode(mid+1,pos->r);
}

void pushup(segtree *pos)
{
    if(!pos->lson)  pos->lson = newlson(pos);
    if(!pos->rson)  pos->rson = newrson(pos);
    pos->x = min(pos->lson->x,pos->rson->x);
}

void pushdown(segtree *pos)
{
    if(!pos->lson)  pos->lson = newlson(pos);
    if(!pos->rson)  pos->rson = newrson(pos);
    if(pos->lazy)
    {
        pos->lson->x = pos->lazy;
        pos->rson->x = pos->lazy;
        pos->lson->lazy = pos->lazy;
        pos->rson->lazy = pos->lazy;
        pos->lazy = 0;
    }
}

void update(segtree *pos,int l,int r,int x)
{
    if(r < pos->l || pos->r < l)    return;
    if(l <= pos->l && pos->r <= r)
    {
        pos->x = x;
        pos->lazy = x;
        return;
    }
    pushdown(pos);
    update(pos->lson,l,r,x);
    update(pos->rson,l,r,x);
    pushup(pos);
}

int getmin(segtree *pos,int l,int r)
{
    if(r < pos->l || pos->r < l)    return 1e9;
    if(l <= pos->l && pos->r <= r)  return pos->x;
    pushdown(pos);
    return min(getmin(pos->lson,l,r),getmin(pos->rson,l,r));
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    st.init();
    root = newnode(1,n*k);
    cin >> q;
    while(q--)
    {
        int x,l,r,y;
        cin >> x >> l >> r;
        if(x == 1)
        {
            cin >> y;
            update(root,l,r,y);
        }
        else    cout << getmin(root,l,r) << endl;
    }
	return 0;
}
