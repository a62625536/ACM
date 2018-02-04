#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long dp[705][705][3][3] = {0},a[705] = {0};
string s;

void dfs(int l,int r)
{
    if(l > r)   return;
    if(l+1 == r)
    {
        dp[l][r][0][1] = 1;
        dp[l][r][1][0] = 1;
        dp[l][r][0][2] = 1;
        dp[l][r][2][0] = 1;
        return;
    }
    if(a[l] == r)
    {
        dfs(l+1,r-1);
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                if(i != 1)  dp[l][r][1][0] = (dp[l][r][1][0]+dp[l+1][r-1][i][j])%MOD;
                if(j != 1)  dp[l][r][0][1] = (dp[l][r][0][1]+dp[l+1][r-1][i][j])%MOD;
                if(i != 2)  dp[l][r][2][0] = (dp[l][r][2][0]+dp[l+1][r-1][i][j])%MOD;
                if(j != 2)  dp[l][r][0][2] = (dp[l][r][0][2]+dp[l+1][r-1][i][j])%MOD;
            }
        }
        return;
    }
    dfs(l,a[l]);
    dfs(a[l]+1,r);
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            for(int ii = 0;ii < 3;ii++)
            {
                for(int jj = 0;jj < 3;jj++)
                {
                    if(ii == 1 && jj == 1 || ii == 2 && jj == 2)    continue;
                    dp[l][r][i][j] = (dp[l][r][i][j]+dp[l][a[l]][i][ii]*dp[a[l]+1][r][jj][j])%MOD;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    int len = s.length();
    s = " "+s;
    stack<int> st;
    for(int i = 1;i <= len;i++)
    {
        if(s[i] == '(') st.push(i);
        else
        {
            a[st.top()] = i;
            st.pop();
        }
    }
    dfs(1,len);
    long long ans = 0;
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)    ans = (ans+dp[1][len][i][j])%MOD;
    }
    cout << ans << endl;
    return 0;
}
