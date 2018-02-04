
By a62625536, contest: Codeforces Round #426 (Div. 2), problem: (D) The Bakery, Accepted, #
 #include<bits/stdc++.h>
using namespace std;

int n,k,a[35005],pre[35005] = {0},lastt[35005] = {0},dp[35005];

struct xx
{
    int l,r,x,lazy;
}tree[35005*4];

void pushup(int pos)
{
    tree[pos].x = max(tree[pos<<1].x,tree[pos<<1|1].x);
}

void pushdown(int pos)
{
    if(tree[pos].lazy)
    {
        int t = tree[pos].lazy;
        tree[pos<<1].x += t;
        tree[pos<<1|1].x += t;
        tree[pos<<1].lazy += t;
        tree[pos<<1|1].lazy += t;
        tree[pos].lazy = 0;
    }
}

void build(int pos,int l,int r)
{
    tree[pos].l = l;
    tree[pos].r = r;
    tree[pos].lazy = 0;
    if(l >= r)
    {
        tree[pos].x = dp[l];
        return;
    }
    int mid = (l+r)/2;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}

void update(int pos,int l,int r)
{
    if(l <= tree[pos].l && tree[pos].r <= r)
    {
        tree[pos].x++;
        tree[pos].lazy++;
        return;
    }
    pushdown(pos);
    int mid = (tree[pos].l+tree[pos].r)/2;
    if(l <= mid)    update(pos<<1,l,r);
    if(r > mid)     update(pos<<1|1,l,r);
    pushup(pos);
}

int query(int pos,int l,int r)
{
    if(l <= tree[pos].l && tree[pos].r <= r)    return tree[pos].x;
    pushdown(pos);
    int mid = (tree[pos].l+tree[pos].r)/2;
    if(r <= mid)    return query(pos<<1,l,r);
    if(l > mid)     return query(pos<<1|1,l,r);
    return max(query(pos<<1,l,r),query(pos<<1|1,l,r));
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    memset(lastt,-1,sizeof(lastt));
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        pre[i] = lastt[a[i]];
        lastt[a[i]] = i;
        if(pre[i] == -1)    cnt++;
        dp[i] = cnt;
    }
    for(int kk = 2;kk <= k;kk++)
    {
        build(1,1,n);
        for(int i = kk;i <= n;i++)
        {
            update(1,max(1,pre[i]),i-1);
            dp[i] = query(1,1,i-1);
        }
    }
    cout << dp[n] << endl;
	return 0;
}
