#include<bits/stdc++.h>
using namespace std;

int n,X,Y,tree[100005];

inline int lowbitt(int x)
{
    return x&-x;
}

void add(int pos,int x)
{
    while(pos <= 100000)
    {
        tree[pos] += x;
        pos += lowbitt(pos);
    }
}

int getsum(int pos)
{
    int ans = 0;
    while(pos > 0)
    {
        ans += tree[pos];
        pos -= lowbitt(pos);
    }
    return ans;
}

struct xx
{
    int x,y;
    friend bool operator<(xx a,xx b)
    {
        return a.x < b.x;
    }
}a[100005];

int main()
{
    ios::sync_with_stdio(false);
    while(~scanf("%d%d%d",&n,&X,&Y))
    {
        memset(tree,0,sizeof(tree));
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i].x);
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i].y);
        sort(a+1,a+1+n);
        int now = 1,r = 1;
        long long ans = 0;
        for(int i = n;i >= 1;i--)
        {
            while(a[r].x <= X-a[i].x)   r++;
            while(now > i)
            {
                --now;
                add(a[now].y,-1);
            }
            while(now < i && now < r)
            {
                add(a[now].y,1);
                now++;
            }
            ans += getsum(Y-a[i].y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
