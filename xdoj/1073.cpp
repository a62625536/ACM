#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[1005],dp[5005];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&w[i]);
            sum += w[i];
        }
        if(sum&1)
        {
            printf("No\n");
            continue;
        }
        int endd = sum/2;
        for(int i = 1;i <= n;i++)
        {
            for(int j = endd;j >= w[i];j--)  dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
        }
        if(dp[endd] == endd)    printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
