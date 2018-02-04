#include<bits/stdc++.h>
using namespace std;

int n,maxx = 0,cnt[1000005] = {0};

bool ok(int x)
{
    if(x < maxx)    return 0;
    if(x-maxx > 30) return 1;
    int now = 1;
    for(int i = 0;i <= x;i++)
    {
        if(now > 1e6)   break;
        if(cnt[x-i] > now) return 0;
        now -= cnt[x-i];
        now *= 2;
    }
    return 1;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
        maxx = max(maxx,x);
    }
    int l = 0,r = 1e6+50;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else  l = mid+1;
    }
    printf("%d\n",l);
    return 0;
}
