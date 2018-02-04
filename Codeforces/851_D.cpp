#include<bits/stdc++.h>
using namespace std;

int n,cnt[2000005] = {0},vis[2000005] = {0};
long long x,y,sum[2000005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> x >> y;
    for(int i = 1 ;i <= n;i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        sum[x] += x;
    }
    for(int i = 1;i <= 2000000;i++)
    {
        cnt[i] += cnt[i-1];
        sum[i] += sum[i-1];
    }
    long long ans = 1e18;
    for(int i = 2;i <= 1000000;i++)
    {
        if(vis[i])  continue;
        long long xx = 0;
        for(int j = i;j <= 1000000+i;j += i)
        {
            vis[j] = 1;
            int t = max(j-(int)(x/y),j-i+1);
            xx += ((long long)(cnt[j]-cnt[t-1])*j-(sum[j]-sum[t-1]))*y;
            xx += (cnt[t-1]-cnt[j-i])*x;
        }
        ans = min(ans,xx);
    }
    cout << ans << endl;
    return 0;
}
