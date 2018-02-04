#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct arr
{
    int o,x,pos,l,r;
}a[300005];
int n,m,tree[300005] = {0},ans1[100005],ans2[100005];

bool cmp(arr X,arr Y)
{
    if(X.x == Y.x)  return X.o < Y.o;
    return X.x < Y.x;
}

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int pos,int x)
{
    while(pos <= n)
    {
        tree[pos] += x;
        pos += lowbit(pos);
    }
}

int getsum(int pos)
{
    int sum = 0;
    while(pos > 0)
    {
        sum += tree[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(tree,0,sizeof(tree));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i].x);
            a[i].pos = i;
            a[i].o = 1;
        }
        int cnt = n;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d%d",&a[cnt+1].l,&a[cnt+1].r,&a[cnt+1].x,&a[cnt+2].x);
            a[cnt+1].o = 0;
            a[cnt+2].o = 2;
            a[cnt+1].pos = a[cnt+2].pos = i;
            a[cnt+2].l = a[cnt+1].l;
            a[cnt+2].r = a[cnt+1].r;
            cnt += 2;
        }
        sort(a+1,a+1+cnt,cmp);
        for(int i = 1;i <= cnt;i++)
        {
            if(a[i].o == 1)     update(a[i].pos,1);
            else if(a[i].o == 0)    ans1[a[i].pos] = getsum(a[i].r)-getsum(a[i].l-1);
            else    ans2[a[i].pos] = getsum(a[i].r)-getsum(a[i].l-1);
        }
        for(int i = 1;i <= m;i++)   printf("%d\n",ans2[i]-ans1[i]);
    }
    return 0;
}

