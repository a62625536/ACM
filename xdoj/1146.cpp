#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[50005],v[1005],w[1005],n,W;

int main()
{
    while(~scanf("%d%d",&n,&W))
    {
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&w[i],&v[i]);
            sum += v[i];
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = sum;j >= v[i];j--)  dp[j] = min(dp[j-v[i]]+w[i],dp[j]);
        }
        for(int i = sum;i >= 0;i--)
        {
            if(dp[i] <= W)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
