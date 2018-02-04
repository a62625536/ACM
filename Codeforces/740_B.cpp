#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,a[105];

int main()
{
    int ans = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    for(int i = 1;i <= m;i++)
    {
        int l,r,sum = 0;
        scanf("%d%d",&l,&r);
        for(int j = l;j <= r;j++)   sum += a[j];
        if(sum > 0) ans += sum;
    }
    printf("%d\n",ans);
    return 0;
}
