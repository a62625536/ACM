#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
struct line
{
    int x,y;
}l[50005];

bool cmp(line a,line b)
{
    return a.x < b.x;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d%d",&l[i].x,&l[i].y);
    sort(l+1,l+1+n,cmp);
    int endd = l[1].y,ans = 0;
    for(int i = 2;i <= n;i++)
    {
        ans = max(ans,min(endd,l[i].y)-l[i].x);
        endd = max(l[i].y,endd);
    }
    printf("%d\n",ans);
    return 0;
}
