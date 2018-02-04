#include<bits/stdc++.h>
using namespace std;

int n;
long long a[3005],b[3005],dp[3005][3005];

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        a[i] -= i;
        b[i] = a[i];
    }
    sort(b+1,b+1+n);
    for(int i = 1;i <= n;i++)
    {
        long long minn = dp[i-1][1];
        for(int j = 1;j <= n;j++)
        {
            minn = min(minn,dp[i-1][j]);
            dp[i][j] = abs(a[i]-b[j])+minn;
        }
    }
    long long ans = dp[n][1];
    for(int i = 1;i <= n;i++)   ans = min(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}

