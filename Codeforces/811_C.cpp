#include<bits/stdc++.h>
using namespace std;

int n,a[5005],dp[5005] = {0},cnt[5005] = {0},num[5005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)   cnt[a[i]]++;
    for(int i = 1;i <= n;i++)
    {
        dp[i] = dp[i-1];
        memset(num,0,sizeof(num));
        int ok = 0,t = 0;
        for(int j = i;j >= 1;j--)
        {
            if(!num[a[j]])
            {
                ok++;
                t ^= a[j];
            }
            if(++num[a[j]] == cnt[a[j]])  ok--;
            if(ok == 0) dp[i] = max(dp[i],dp[j-1]+t);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
