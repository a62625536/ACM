#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int link[100005][2],ans[100005];

int main()
{
    int now,i,n,re;
    scanf("%d%d%d",&now,&n,&re);
    for(i = 1;i <= n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        link[a][0] = b;
        link[a][1] = c;
    }
    int counts = 1;
    while(now != -1)
    {
        ans[counts++] = now;
        now = link[now][1];
    }
    i = 1;
    while(i+re <= counts)
    {
        reverse(ans+i,ans+i+re);
        i += re;
    }
    for(i = 1;i < counts-1;i++)  printf("%05d %d %05d\n",ans[i],link[ans[i]][0],ans[i+1]);
    printf("%05d %d -1\n",ans[i],link[ans[i]][0]);
    return 0;
}
