#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[100005];
struct segtree
{
    int l,r;
    long long x,sum;
}tree[400005];


void pushup(int pos)
{
    tree[pos].x = max(tree[pos<<1].x,tree[pos<<1|1].x);
    tree[pos].sum = tree[pos<<1].sum+tree[pos<<1|1].sum;
}

void build(int pos,int l,int r)
{
    tree[pos].l = l;
    tree[pos].r = r;
    if(l >= r)
    {
        tree[pos].x = a[l];
        tree[pos].sum = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}

void edit(int pos,int l,int r,long long x,int t)
{
    if(t < l || t > r)  return;
    if(l == r)
    {
        tree[pos].x = x;
        tree[pos].sum = x;
        return;
    }
    int mid = (l+r)/2;
    edit(pos<<1,l,mid,x,t);
    edit(pos<<1|1,mid+1,r,x,t);
    pushup(pos);
}

void mod(int pos,int l,int r,long long x)
{
    if(r < tree[pos].l || tree[pos].r < l || tree[pos].x < x)   return;
    if(tree[pos].l == tree[pos].r)
    {
        tree[pos].x %= x;
        tree[pos].sum = tree[pos].x;
        return;
    }
    int mid = (tree[pos].l+tree[pos].r)/2;
    mod(pos<<1,l,r,x);
    mod(pos<<1|1,l,r,x);
    pushup(pos);
}

long long getsum(int pos,int l,int r)
{
    if(r < tree[pos].l || tree[pos].r < l)  return 0;
    if(l <= tree[pos].l && tree[pos].r <= r)    return tree[pos].sum;
    int mid = (tree[pos].l+tree[pos].r)/2;
    return  getsum(pos<<1,l,r)+getsum(pos<<1|1,l,r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    build(1,1,n);
    for(int i = 1;i <= m;i++)
    {
        int z,l,r,x;
        cin >> z;
        if(z == 1)
        {
            cin >> l >> r;
            cout << getsum(1,l,r) << endl;
        }
        else if(z == 2)
        {
            cin >> l >> r >> x;
            mod(1,l,r,x);
        }
        else
        {
            cin >> l >> x;
            edit(1,1,n,x,l);
        }
    }
    return 0;
}
