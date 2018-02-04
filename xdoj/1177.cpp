#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int tree[1000005],n,m,cnt = 1,ans[100005];

struct star
{
    int num,x,y,o;
}a[200005];

bool cmp(star X,star Y)
{
    if(X.x == Y.x)  return X.y < Y.y;
    return X.x < Y.x;
}

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int pos,int x)
{
    while(pos <= 1000001)
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
        printf("Case #%d:\n",cnt++);
        memset(tree,0,sizeof(tree));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].o = 1;
        }
        for(int i = n+1;i <= n+m;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].num = i-n;
            a[i].o = 0;
        }
        sort(a+1,a+1+n+m,cmp);
        for(int i = 1;i <= n+m;i++)
        {
            if(a[i].o)  update(a[i].y+1,1);
            else    ans[a[i].num] = getsum(a[i].y+1);
        }
        for(int i = 1;i <= m;i++)   printf("%d\n",ans[i]);
    }
    return 0;
}
