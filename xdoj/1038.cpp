#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[15][15],sta[100],dp[15][100],sum[15][100],n,m;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)   scanf("%d",&a[i][j]);
        }
        int cnt = 0,endd = 1<<(m-1);
        for(int i = 0;i < endd;i++)
        {
            if(i & (i<<1))  continue;
            sta[++cnt] = i;
        }
        for(int i = 1;i < n;i++)
        {
            for(int j = 1;j <= cnt;j++)
            {
                for(int k = 1;k <= m-1;k++)
                {
                    if(1<<(k-1) & sta[j])
                    {
                        if(a[i][k] && a[i][k+1] && a[i+1][k] && a[i+1][k+1])    sum[i][j]++;
                    }
                }
            }
        }
        for(int i = 1;i <= cnt;i++) dp[1][i] = sum[1][i];
        for(int i = 1;i < n;i++)
        {
            for(int j = 1;j <= cnt;j++)
            {
                for(int k = 1;k <= cnt;k++)
                {
                    dp[i+2][k] = max(dp[i+2][k],dp[i][j]+sum[i+2][k]);
                    if(sta[j] & sta[k])         continue;
                    if(sta[j] & (sta[k]<<1))    continue;
                    if(sta[j] & (sta[k]>>1))    continue;
                    dp[i+1][k] = max(dp[i+1][k],dp[i][j]+sum[i+1][k]);
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= cnt;i++) ans = max(ans,dp[n-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
