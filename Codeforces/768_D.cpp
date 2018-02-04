#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int k,q,ans[1005];
double dp[10005][1005];

int main()
{
    cin >> k >> q;
    dp[0][0] = 1;
    for(int i = 1;i <= 10000;i++)
    {
        dp[i][0] = 0;
        for(int j = 1;j <= k;j++)   dp[i][j] = (dp[i-1][j]*j+dp[i-1][j-1]*(k-j+1))/k;
    }
    int now = 1;
    for(int i = 1;i <= 1000;i++)
    {
        while(dp[now][k] < (double)i/2000)  now++;
        ans[i] = now;
    }
    while(q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}
