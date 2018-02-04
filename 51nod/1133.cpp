#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct line
{
    int x,y;
}l[10005];
int n;

bool cmp(line a,line b)
{
    return a.y < b.y;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d%d",&l[i].x,&l[i].y);
    sort(l+1,l+1+n,cmp);
    int ans = 0,endd = -1e9;
    for(int i = 1;i <= n;i++)
    {
        if(l[i].x >= endd)
        {
            ans++;
            endd = l[i].y;
        }
    }
    printf("%d\n",ans);
    return 0;

}
