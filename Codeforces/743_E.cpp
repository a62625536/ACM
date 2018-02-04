#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,a[1005],cnt[8],dp[1005][1<<8];
vector<int> v[8];

int ok(int len)
{
    int endd = 1<<8,ans = 0;
    memset(cnt,0,sizeof(cnt));
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < endd;j++) dp[i][j] = -1;
    }
    dp[1][0] = 0;
    bool flag = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < endd;j++)
        {
            if(dp[i][j] == -1)  continue;
            for(int k = 0;k < 8;k++)
            {
                if(j&(1<<k))    continue;
                int t = cnt[k]+len-1;
                if(t >= v[k].size())    continue;
                int tt = v[k][t];
                dp[tt][j|(1<<k)] = max(dp[tt][j|(1<<k)],dp[i][j]);
                t++;
                if(t >= v[k].size())    continue;
                tt = v[k][t];
                dp[tt][j|(1<<k)] = max(dp[tt][j|(1<<k)],dp[i][j]+1);
            }
            if(j == endd-1)
            {
                ans = max(ans,dp[i][j]);
                flag = 1;
            }
        }
        cnt[a[i]]++;
    }
    ans += 8*len;
    if(flag)    return ans;
    else    return -1;
}

int main()
{
    cin >> n;
    int flag = 0,num = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        v[--a[i]].push_back(i);
        if((flag & 1<<a[i]) == 0)
        {
            flag |= 1<<a[i];
            num++;
        }
    }
    if(num < 8)
    {
        cout << num << endl;
        return 0;
    }
    int l = 1,r = n/8;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(ok(mid) != -1)   l = mid;
        else    r = mid-1;
    }
    cout << ok(l) << endl;
    return 0;
}
