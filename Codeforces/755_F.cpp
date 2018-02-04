#include<bits/stdc++.h>
using namespace std;

int n,k,p[1000005],vis[1000005] = {0},a[1000005],w[1000005],dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1;i <= n;i++)   cin >> p[i];
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])  continue;
        int t = i,sum = 0;
        while(!vis[t])
        {
            vis[t] = 1;
            sum++;
            t = p[t];
        }
        a[++cnt] = sum;
    }
    int ans2 = 0,t = k;
    for(int i = 1;i <= cnt;i++)
    {
        if(a[i]/2 < t)
        {
            t -= a[i]/2;
            ans2 += a[i]/2*2;
        }
        else
        {
            ans2 += t*2;
            t = 0;
            break;
        }
    }
    ans2 = min(n,ans2+t);
    sort(a+1,a+1+cnt);
    int num = 0;
    for(int i = 1;i <= cnt;i++)
    {
        int j = i;
        while(j+1 <= cnt && a[j+1] == a[j]) j++;
        int len = j-i+1,t = 1;
        while(len >= t)
        {
            w[++num] = t*a[i];
            len -= t;
            t *= 2;
        }
        if(len) w[++num] = len*a[i];
        i = j;
    }
    dp[0] = 1;
    for(int i = 1;i <= num;i++)
    {
        for(int j = k-w[i];j >= 0;j--)
        {
            if(dp[j])   dp[j+w[i]] = 1;
        }
    }
    int ans1 = k;
    if(!dp[k])  ans1++;
    cout << ans1 << " " << ans2 << endl;
	return 0;
}
