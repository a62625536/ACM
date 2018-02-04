#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int dp[105][105],n,m;
vector<int> v[105];

void dfs(int pos,int pre)
{
    for(int i = 0;i < v[pos].size();i++)
    {
        if(v[pos][i] == pre)    continue;
        int x = v[pos][i];
        dfs(x,pos);
        for(int j = m;j > 1;j--)
        {
            for(int k = 1;k <= j;k++)
            {
                dp[pos][j] = max(dp[pos][j],dp[x][j-k]+dp[pos][k]);
            }
        }
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < n;i++)    v[i].clear();
        for(int i = 0;i < n;i++)    scanf("%d",&dp[i][1]);
        for(int i = 1;i < n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(0,-1);
        int ans = 0;
        for(int i = 0;i < n;i++)    ans = max(ans,dp[i][m]);
        printf("%d\n",ans);
    }
    return 0;
}
