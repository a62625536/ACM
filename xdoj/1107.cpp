#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct point
{
    int x,y;
}a[100005];
int b[100005],n;

bool cmp(point X,point Y)
{
    if(X.x == Y.x)  return X.y > Y.y;
    return X.x < Y.x;
}

int LIS()
{
    int len = 1,j;
    b[1] = a[1].y;
    for(int i = 2;i <= n;i++)
    {
        if(a[i].y > b[len]) j = ++len;
        else    j = lower_bound(b+1,b+1+len,a[i].y)-b;
        b[j] = a[i].y;
    }
    return len;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i].x);
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i].y);
        sort(a+1,a+1+n,cmp);
        printf("%d\n",LIS());
    }
    return 0;
}
