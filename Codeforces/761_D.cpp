#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int n,l,r,a[100005],p[100005],b[100005];

int main()
{
    cin >> n >> l >> r;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)   cin >> p[i];
    int minn = INF,maxx = -INF;
    for(int i = 1;i <= n;i++)
    {
        b[i] = a[i]+p[i];
        minn = min(minn,b[i]);
        maxx = max(maxx,b[i]);
    }
    if(maxx-minn > r-l) printf("-1\n");
    else
    {
        for(int i = 1;i <= n;i++)
        {
            printf("%d ",b[i]-minn+l);
        }
        printf("\n");
    }
    return 0;
}
