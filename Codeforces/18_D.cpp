#include<bits/stdc++.h>
using namespace std;

int n,a[5005],pre[2005] = {0};
bitset<2005> dp[5005],t;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s >> a[i];
        if(s == "win")
        {
            pre[a[i]] = i;
            dp[i] = dp[i-1];
        }
        else
        {
            if(!pre[a[i]])
            {
                dp[i] = dp[i-1];
                continue;
            }
            t = dp[pre[a[i]]];
            t[a[i]] = 1;
            for(int j = 2000;j >= 0;j--)
            {
                if(dp[i-1][j] > t[j])
                {
                    dp[i] = dp[i-1];
                    break;
                }
                if(dp[i-1][j] < t[j])
                {
                    dp[i] = t;
                    break;
                }
                if(j == 0)  dp[i] = t;
            }
        }
    }
    ans.push_back(0);
    for(int i = dp[n].size()-1;i>= 0;i--)
    {
        int k = 0;
        for(int j = 0;j < ans.size();j++)
        {
            int t = ans[j]*2+k;
            ans[j] = t%10;
            k = t/10;
        }
        if(k)   ans.push_back(k);
        if(dp[n][i])
        {
            ans[0]++;
            int k = 0;
            for(int j = 0;j < ans.size();j++)
            {
                int t = ans[j]+k;
                ans[j] = t%10;
                k = t/10;
            }
            if(k)   ans.push_back(k);
        }
    }
    for(int i = ans.size()-1;i >= 0;i--)    cout << ans[i];
    cout << endl;
	return 0;
}
