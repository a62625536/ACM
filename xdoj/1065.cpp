#include<bits/stdc++.h>
using namespace std;

int n,q,cnt = 0,a[100005];
struct segtree
{
    int l,r,lazy,len,x,lx,rx;
    segtree *lson,*rson;
}*root,tree[3000005];

segtree *newnode(int l,int r)
{
    segtree *t = &tree[++cnt];
    t->l = l;
    t->r = r;
    t->lson = NULL;
    t->rson = NULL;
    t->lazy = -1;
    t->len = r-l+1;
    t->x = t->len;
    t->lx = t->len;
    t->rx = t->len;
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
    pos->lx = pos->lson->lx;
    pos->rx = pos->rson->rx;
    pos->x = max(pos->lson->x,pos->rson->x);
    if(pos->lx == pos->lson->len)   pos->lx += pos->rson->lx;
    if(pos->rx == pos->rson->len)   pos->rx += pos->lson->rx;
    pos->x = max(pos->x,pos->lson->rx+pos->rson->lx);
}

void pushdown(segtree *pos)
{
    if(!pos->lson)  pos->lson = newlson(pos);
    if(!pos->rson)  pos->rson = newrson(pos);
    if(pos->lazy != -1)
    {
        pos->lson->lazy = pos->lazy;
        pos->rson->lazy = pos->lazy;
        pos->lson->x = pos->lson->lx = pos->lson->rx = pos->lazy*pos->lson->len;
        pos->rson->x = pos->rson->lx = pos->rson->rx = pos->lazy*pos->rson->len;
        pos->lazy = -1;
    }
}

void update(segtree *pos,int l,int r,int x)
{
    if(r < pos->l || pos->r < l)    return;
    if(l <= pos->l && pos->r <= r)
    {
        pos->x = pos->lx = pos->rx = pos->len*x;
        pos->lazy = x;
        return;
    }
    pushdown(pos);
    update(pos->lson,l,r,x);
    update(pos->rson,l,r,x);
    pushup(pos);
}

int getl(segtree *pos,int x)
{
    if(pos->x < x)  return 2e9;;
    if(pos->lx >= x)    return pos->l;
    pushdown(pos);
    int minn = 2e9;
    if(pos->lson->rx+pos->rson->lx >= x)    minn = pos->lson->r-pos->lson->rx+1;
    minn = min(minn,getl(pos->lson,x));
    minn = min(minn,getl(pos->rson,x));
    return minn;
}

int main()
{
    while(~scanf("%d%d",&n,&q))
    {
        set<int> s;
        map<int,int> mp;
        cnt = 0;
        root = newnode(1,n);
        while(q--)
        {
            char ss[20];
            int x;
            scanf("%s",ss);
            if(ss[0] == 'm')
            {
                sscanf(ss,"malloc(%d)",&x);
                int t = getl(root,x);
                if(t == 2e9)   printf("0\n");
                else
                {
                    printf("%d\n",t);
                    update(root,t,t+x-1,0);
                    s.insert(t);
                    mp[t] = t+x-1;
                }
            }
            else
            {
                sscanf(ss,"free(%d)",&x);
                auto it = s.lower_bound(x);
                if(it == s.end() || *it != x)   continue;
                update(root,*it,mp[*it],1);
                s.erase(it);
            }
        }
    }
	return 0;
}
