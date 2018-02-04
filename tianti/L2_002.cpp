#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct xx
{
    int v,next;
}a[100005];
int n,s,vis[100005],ans1[100005],ans2[100005];

int main()
{
    ios::sync_with_stdio(false);
    scanf("%d%d",&s,&n);
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d",&x);
        scanf("%d%d",&a[x].v,&a[x].next);
    }
    for(int i = s;i != -1;i = a[i].next)
    {
        int t = abs(a[i].v);
        if(vis[t])  ans2[++cnt2] = i;
        else
        {
            vis[t] = 1;
            ans1[++cnt1] = i;
        }
    }
    for(int i = 1;i < cnt1;i++)
    {
        printf("%05d %d %05d\n",ans1[i],a[ans1[i]].v,ans1[i+1]);
    }
    printf("%05d %d -1\n",ans1[cnt1],a[ans1[cnt1]].v);
    if(cnt2 == 0)   return 0;
    for(int i = 1;i < cnt2;i++)
    {
        printf("%05d %d %05d\n",ans2[i],a[ans2[i]].v,ans2[i+1]);
    }
    printf("%05d %d -1\n",ans2[cnt2],a[ans2[cnt2]].v);
    return 0;
}
