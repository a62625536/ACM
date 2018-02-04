#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    int ans = 1e5;
    for(int i = 1;i <= m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        ans = min(ans,r-l+1);
    }
    printf("%d\n",ans);
    int t = 0;
    for(int i = 1;i <= n;i++)
    {
        printf("%d ",t);
        t++;
        if(t == ans)    t = 0;
    }
    return 0;
}
