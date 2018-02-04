#include<bits/stdc++.h>
using namespace std;

string s;
int lcp[8005][8005] = {0},dp[8005],cnt[8005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    int n = s.length();
    memset(dp,0x3f,sizeof(dp));
    for(int i = 1;i <= 9;i++)   cnt[i] = 1;
    for(int i = 10;i <= 99;i++) cnt[i] = 2;
    for(int i = 100;i <= 999;i++)   cnt[i] = 3;
    for(int i = 1000;i <= 8000;i++) cnt[i] = 4;
    for(int i = n-1;i >= 0;i--)
    {
        for(int j = n-1;j >= i;j--)
        {
            if(s[i] == s[j])    lcp[i][j] = lcp[i+1][j+1]+1;
            else    lcp[i][j] = 0;
        }
    }
    dp[0] = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 1;i+j <= n;j++)
        {
            for(int k = i+j,t = 1;k <= n;k += j,t++)
            {
                if(lcp[i][k-j] < j)  break;
                dp[k] = min(dp[k],dp[i]+j+cnt[t]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
