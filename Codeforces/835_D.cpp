#include<bits/stdc++.h>
using namespace std;

string s;
int dp[5005][5005] = {0},ans[5005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    s = ' '+s;
    for(int i = 1;i < s.length();i++)   dp[i][i] = 1;
    for(int i = 2;i < s.length();i++)
    {
        if(s[i-1] == s[i])  dp[i-1][i] = 2;
    }
    for(int len = 3;len < s.length();len++)
    {
        for(int l = 1;l+len-1 < s.length();l++)
        {
            int r = l+len-1;
            if(s[l] != s[r] || !dp[l+1][r-1])    continue;
            dp[l][r] = dp[l][l+len/2-1]+1;
        }
    }
    for(int i = 1;i < s.length();i++)
    {
        for(int j = i;j < s.length();j++)   ans[dp[i][j]]++;
    }
    for(int i = s.length()-1;i >= 1;i--)    ans[i] += ans[i+1];
    for(int i = 1;i < s.length();i++)   cout << ans[i] << " ";
    cout << endl;
	return 0;
}
