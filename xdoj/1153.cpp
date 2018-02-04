#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;

struct line
{
    LL x,y;
}a[100005];
int n;

bool cmp(line X,line Y)
{
    return X.y*Y.x < X.x*Y.y;
}

int main()
{
    while(~scanf("%d",&n))
    {
        int cnt = 0;
        LL x,y,xx,yy,temp = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld%lld%lld%lld",&x,&y,&xx,&yy);
            if(x == xx) temp++;
            else if(x < xx)
            {
                a[cnt].x = xx-x;
                a[cnt].y = yy-y;
                cnt++;
            }
            else
            {
                a[cnt].x = x-xx;
                a[cnt].y = y-yy;
                cnt++;
            }
        }
        sort(a,a+cnt,cmp);
        LL ans = temp*(temp-1)/2;
        LL num = 1;
        for(int i = 1;i < cnt;i++)
        {
            if(a[i].x*a[i-1].y == a[i].y*a[i-1].x)  num++;
            else
            {
                ans += num*(num-1)/2;
                num = 1;
            }
        }
        ans += num*(num-1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}
