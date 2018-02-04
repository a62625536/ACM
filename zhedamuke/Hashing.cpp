#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int m,n,t,ans[10005] = {0},h[20005];

int nextprime(int x)
{
    if(x == 0 || x == 1)    return 2;
    if(x == 2 || x == 3)    return x;
    int i,t = x%2?x:x+1;
    while(t < 20000)
    {
        for(i = sqrt(t);i > 2;i--)
        {
            if(t%i == 0)    break;
        }
        if(i == 2)  break;
        else    t += 2;
    }
    return t;
}

void insertt(int pos,int xx)
{
    int x = xx%m;
    int p = x,t = 0;
    if(h[p])
    {
        for(t = 1;t < m;t++)
        {
            p = (x+t*t)%m;
            if(h[p] == 0)   break;
        }
    }
    if(t < m)
    {
        ans[pos] = p;
        h[p] = xx;
    }
    else    ans[pos] = -1;
}

int main()
{
    scanf("%d%d",&m,&n);
    m = nextprime(m);
    memset(h,0,sizeof(h));
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&t);
        insertt(i,t);
    }
    if(ans[1] == -1)    printf("-");
    else    printf("%d",ans[1]);
    for(int i = 2;i <= n;i++)
    {
        if(ans[i] == -1)    printf(" -");
        else    printf(" %d",ans[i]);
    }
    printf("\n");
    return 0;
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int m,n,t,ans[10005] = {0},h[20005];

int nextprime(int x)
{
    if(x == 0 || x == 1)    return 2;
    if(x == 2 || x == 3)    return x;
    int i,t = x%2?x:x+1;
    while(t < 20000)
    {
        for(i = sqrt(t);i > 2;i--)
        {
            if(t%i == 0)    break;
        }
        if(i == 2)  break;
        else    t += 2;
    }
    return t;
}

void insertt(int pos,int xx)
{
    int x = xx%m;
    int p = x,t = 0;
    if(h[p])
    {
        for(t = 1;t < m;t++)
        {
            p = (x+t*t)%m;
            if(h[p] == 0)   break;
        }
    }
    if(t < m)
    {
        ans[pos] = p;
        h[p] = xx;
    }
    else    ans[pos] = -1;
}

int main()
{
    scanf("%d%d",&m,&n);
    m = nextprime(m);
    memset(h,0,sizeof(h));
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&t);
        insertt(i,t);
    }
    if(ans[1] == -1)    printf("-");
    else    printf("%d",ans[1]);
    for(int i = 2;i <= n;i++)
    {
        if(ans[i] == -1)    printf(" -");
        else    printf(" %d",ans[i]);
    }
    printf("\n");
    return 0;
}
