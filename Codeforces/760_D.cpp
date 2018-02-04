#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[100005],dp[100005] = {0};

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        dp[i] = dp[i-1]+20;
        for(int j = i-1;j >= 1;j--)
        {
            if(a[i]-a[j] < 90)  dp[i] = min(dp[i],dp[j-1]+50);
            else if(a[i]-a[j] < 1440)   dp[i] = min(dp[i],dp[j-1]+120);
            else    break;
        }
    }
    for(int i = n;i >= 1;i--)   dp[i] = dp[i]-dp[i-1];
    for(int i = 1;i <= n;i++)   cout << dp[i] << endl;
    return 0;
}
