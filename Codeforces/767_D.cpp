#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct xx
{
    int x,id;
}b[1000005];
int n,m,k,a[1000005];

bool cmp(xx a,xx b)
{
    return a.x < b.x;
}

bool ok(int x)
{
    int now1 = 1,now2 = m-x+1,day = 0,cnt = k;
    while(now1 <= n && now2 <= m)
    {
        if(a[now1] < day || b[now2].x < day)    return 0;
        if(a[now1] < b[now2].x) now1++;
        else    now2++;
        cnt--;
        if(cnt == 0)
        {
            day++;
            cnt = k;
        }
    }
    while(now1 <= n)
    {
        if(a[now1] < day)   return 0;
        now1++;
        cnt--;
        if(cnt == 0)
        {
            day++;
            cnt = k;
        }
    }
    while(now2 <= m)
    {
        if(b[now2].x < day) return 0;
        now2++;
        cnt--;
        if(cnt == 0)
        {
            day++;
            cnt = k;
        }
    }
    return 1;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&b[i].x);
        b[i].id = i;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m,cmp);
    if(!ok(0))
    {
        printf("-1\n");
        return 0;
    }
    int l = 0,r = m;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(ok(mid)) l = mid;
        else    r = mid-1;
    }
    printf("%d\n",l);
    for(int i = m-l+1;i <= m;i++)   printf("%d ",b[i].id);
    printf("\n");
    return 0;
}

