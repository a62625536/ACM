#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct ss
{
    int id,sum,x;
}a[10005];
int s[10005][6] = {0},p[6],n,k,m,flag[10005] ={0};

bool cmp(ss X,ss Y)
{
    if(X.sum == Y.sum && X.x == Y.x)    return X.id < Y.id;
    if(X.sum == Y.sum)  return X.x > Y.x;
    return X.sum > Y.sum;
}
int main()
{
    memset(a,0,sizeof(a));
    memset(s,-1,sizeof(s));
    scanf("%d%d%d",&n,&k,&m);
    for(int i = 1;i <= n;i++)   a[i].id = i;
    for(int i = 1;i <= k;i++)   scanf("%d",&p[i]);
    for(int i = 1;i <= m;i++)
    {
        int uid,pid,ss;
        scanf("%d%d%d",&uid,&pid,&ss);
        if(ss == -1)    ss = 0;
        else    flag[uid] = 1;
        if(s[uid][pid] == -1)   s[uid][pid] = 0;
        if(s[uid][pid] != p[pid] && ss == p[pid])    a[uid].x++;
        ss = max(ss,s[uid][pid]);
        a[uid].sum += ss-s[uid][pid];
        s[uid][pid] = ss;
    }
    sort(a+1,a+1+n,cmp);
    int last = 1;
    for(int i = 1;i <= n;i++)
    {
        if(!flag[a[i].id])  continue;
        if(a[i].sum != a[i-1].sum)  last = i;
        printf("%d %05d %d",last,a[i].id,a[i].sum);
        for(int j = 1;j <= k;j++)
        {
            if(s[a[i].id][j] == -1) printf(" -");
            else    printf(" %d",s[a[i].id][j]);
        }
        printf("\n");
    }
    return 0;
}
