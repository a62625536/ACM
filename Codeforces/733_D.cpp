#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct xxx
{
    int a,b,c,p;
}xx[100005];
int n,x[3];

bool cmp(xxx X,xxx Y)
{
    if(X.a == Y.a && X.b == Y.b)    return X.c > Y.c;
    if(X.a == Y.a)  return X.b > Y.b;
    return X.a > Y.a;
}
int main()
{
    scanf("%d",&n);
    int maxx = 0,ans = 1,ans1,ans2;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d%d",&x[0],&x[1],&x[2]);
        sort(x,x+3);
        xx[i].a = x[2];
        xx[i].b = x[1];
        xx[i].c = x[0];
        xx[i].p = i;
        if(xx[i].c > maxx)
        {
            maxx = xx[i].c;
            ans1 = i;
        }
    }
    sort(xx+1,xx+n+1,cmp);
    for(int i = 1;i < n;i++)
    {
        if(xx[i].a == xx[i+1].a && xx[i].b == xx[i+1].b)
        {
            x[0] = xx[i].a;
            x[1] = xx[i].b;
            x[2] = xx[i].c+xx[i+1].c;
            sort(x,x+3);
            if(x[0] > maxx)
            {
                ans = 2;
                maxx = x[0];
                ans1 = xx[i].p;
                ans2 = xx[i+1].p;
            }
        }
    }
    if(ans == 1)    printf("1\n%d\n",ans1);
    else    printf("2\n%d %d\n",ans1,ans2);
    return 0;
}
