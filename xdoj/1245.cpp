#include<bits/stdc++.h>
using namespace std;

int a[25],b[25],x[25],cnt1,cnt2;
long long n,m,dp[25][25];

long long dfs(int now1,int now2,int limit)
{
    if(now2 == 0)   return 0;
    if(now1 == 0)   return 1;
    if(!limit && dp[now1][now2] != -1)  return dp[now1][now2];
    int endd = limit?a[now1]:9;
    long long ans = 0;
    for(int i = endd;i >= 0;i--)
    {
        int t = now2;
        while(b[t] != i && t != cnt2)   t = x[t];
        if(b[t] == i)   t--;
        ans += dfs(now1-1,t,limit && i == endd);
    }
    if(!limit)  dp[now1][now2] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        cnt1 = 0;
        cnt2 = 0;
        while(n)
        {
            a[++cnt1] = n%10;
            n /= 10;
        }
        while(m)
        {
            b[++cnt2] = m%10;
            m /= 10;
        }
        int i = cnt2,j = cnt2+1;
        x[cnt2] = cnt2+1;
        while(i >= 1)
        {
            if(j == cnt2+1 || b[i] == b[j])   x[--i] = --j;
            else    j = x[j];
        }
        x[cnt2] = cnt2;
        memset(dp,-1,sizeof(dp));
        cout << dfs(cnt1,cnt2,1)-1 << endl;
    }
    return 0;
}
