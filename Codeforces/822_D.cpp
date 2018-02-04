#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int t,l,r;
long long dp[5000005],f[5000005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> t >> l >> r;
    for(int i = 1;i <= r;i++)
    {
        f[i] = (long long)i*(i-1)/2;
        dp[i] = f[i];
    }
    for(int i = 2;i <= r;i++)
    {
        for(int j = i,k = 1;j <= r;j += i,k++)  dp[j] = min(dp[j],dp[i]*k+f[k]);
    }
    long long tt = 1,ans = 0;;
    for(int i = l;i <= r;i++)
    {
        ans = (ans+dp[i]%MOD*tt)%MOD;
        tt = tt*t%MOD;
    }
    cout << ans << endl;
    return 0;
}
