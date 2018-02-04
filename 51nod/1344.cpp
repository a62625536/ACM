#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    long long ans = 0,now = 0;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        now += x;
        if(now < 0)
        {
            ans -= now;
            now = 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
