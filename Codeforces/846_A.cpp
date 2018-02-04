#include<bits/stdc++.h>
using namespace std;

int n,a[105],dp[105][2] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == 0)
        {
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = dp[i-1][1];
        }
        else
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0],dp[i-1][1])+1;
        }
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
    return 0;
}
