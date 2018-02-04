#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007

using namespace std;

struct segtree
{
    int l,r;
    long long sum1,sum2,add;
}tree[400005];

int n,m;

void pushup(int pos)
{
    tree[pos].sum1 = (tree[pos*2].sum1+tree[pos*2+1].sum1)%MOD;
    tree[pos].sum2 = (tree[pos*2].sum2+tree[pos*2+1].sum2)%MOD;
}

void pushdown(int pos)
{
    if(tree[pos].add)
    {
        long long t = tree[pos].add;
        tree[pos*2].add = (tree[pos*2].add+t)%MOD;
        tree[pos*2+1].add = (tree[pos*2+1].add+t)%MOD;
        tree[pos*2].sum2 = (tree[pos*2].sum2+t*t%MOD*(tree[pos*2].r-tree[pos*2].l+1)+2*tree[pos*2].sum1*t)%MOD;
        tree[pos*2+1].sum2 = (tree[pos*2+1].sum2+t*t%MOD*(tree[pos*2+1].r-tree[pos*2+1].l+1)+2*tree[pos*2+1].sum1*t)%MOD;
        tree[pos*2].sum1 = (tree[pos*2].sum1+t*(tree[pos*2].r-tree[pos*2].l+1))%MOD;
        tree[pos*2+1].sum1 = (tree[pos*2+1].sum1+t*(tree[pos*2+1].r-tree[pos*2+1].l+1))%MOD;
        tree[pos].add = 0;
    }
}

void build(int pos,int l,int r)
{
    tree[pos].l = l;
    tree[pos].r = r;
    tree[pos].sum1 = 0;
    tree[pos].sum2 = 0;
    tree[pos].add = 0;
    if(l < r)
    {
        int mid = (l+r)/2;
        build(pos*2,l,mid);
        build(pos*2+1,mid+1,r);
    }
}

void update(int pos,int l,int r,long long x)
{
    if(l <= tree[pos].l && r >= tree[pos].r)
    {
        tree[pos].add = (tree[pos].add+x)%MOD;
        tree[pos].sum2 = (tree[pos].sum2+x*x%MOD*(tree[pos].r-tree[pos].l+1)%MOD+2*tree[pos].sum1*x%MOD)%MOD;
        tree[pos].sum1 = (tree[pos].sum1+x*(tree[pos].r-tree[pos].l+1))%MOD;
        return;
    }
    pushdown(pos);
    int mid = (tree[pos].l+tree[pos].r)/2;
    if(l <= mid)    update(pos*2,l,r,x);
    if(mid < r)     update(pos*2+1,l,r,x);
    pushup(pos);
}

void getsum(int pos,int l,int r,long long &t1,long long &t2)
{
    if(l <= tree[pos].l && tree[pos].r <= r)
    {
        t1 = (t1+tree[pos].sum1)%MOD;
        t2 = (t2+tree[pos].sum2)%MOD;
        return;
    }
    pushdown(pos);
    int mid = (tree[pos].l+tree[pos].r)/2;
    if(l <= mid)    getsum(pos*2,l,r,t1,t2);
    if(mid < r)     getsum(pos*2+1,l,r,t1,t2);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        build(1,1,n);
        while(m--)
        {
            int o,l,r,x;
            scanf("%d",&o);
            if(o == 1)
            {
                scanf("%d%d%d",&l,&r,&x);
                update(1,l,r,x);
            }
            else
            {
                scanf("%d%d",&l,&r);
                long long t1 = 0,t2 = 0;
                getsum(1,l,r,t1,t2);
                long long t = (t1*t1%MOD-t2+MOD)%MOD*500000004%MOD;
                printf("%lld\n",t);
            }
        }
    }
    return 0;
}
