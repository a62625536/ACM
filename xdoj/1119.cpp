#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1005],n,k;

bool ok(int x)
{
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(x%a[i] == 0) cnt++;
    }
    if(cnt >= k)    return 1;
    return 0;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
        int ans = 1;
        for(;ans <=1000;ans++)
        {
            if(ok(ans)) break;
        }
        if(ans <= 1000)   printf("%d\n",ans);
        else    printf("Orz\n");
    }
    return 0;
}
