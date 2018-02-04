#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[205],dp[200005];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        int sum = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&w[i]);
            sum += w[i];
        }
        int endd = sum/2;
        for(int i = 1;i <= n;i++)
        {
            for(int j = endd;j >= w[i];j--)
            {
                dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
            }
        }
        printf("%d\n",sum-dp[endd]*2);
    }
    return 0;
}
