#include<bits/stdc++.h>
using namespace std;

int n,a[50005],dp[50005][2] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 2;i <= n;i++)
    {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]+abs(a[i-1]-1));
        dp[i][1] = max(dp[i-1][0]+abs(a[i]-1),dp[i-1][1]+abs(a[i]-a[i-1]));
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
    return 0;
}
