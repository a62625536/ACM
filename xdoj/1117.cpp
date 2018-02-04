#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define LL long long
#define MOD 1000000007
using namespace std;

int n,m;
LL dp[105][1<<11];
vector<int> v[105];

LL dfs(int left,int sta)
{
    if(dp[left][sta] != -1) return dp[left][sta];
    if(left == 0)   return !sta;
    dp[left][sta] = 0;
    for(int i = 0;i < v[left].size();i++)
    {
        dp[left][sta] = (dp[left][sta]+dfs(left-1,sta^v[left][i]))%MOD;
    }
    return dp[left][sta];
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,-1,sizeof(dp));
        for(int i = 1;i <= m;i++)   v[i].clear();
        for(int i = 1;i <= m;i++)
        {
            int t,endd = 1<<n;
            scanf("%d",&t);
            for(int j = 0;j < endd;j++)
            {
                int sum = 0;
                for(int k = 0;k < n;k++)
                {
                    if(j&(1<<k))    sum++;
                }
                if(sum == t)    v[i].push_back(j);
            }
        }
        int a = 0;
        for(int i = 0;i < n;i++)
        {
            int t;
            scanf("%d",&t);
            a |= (1<<i)*t;
        }
        printf("%lld\n",dfs(m,a));
    }
    return 0;
}
