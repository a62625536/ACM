#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;  
int dp[1005][1005];   
  
int main()  
{  
    int n,k;  
    while(~scanf("%d%d",&n,&k))  
    {  
        memset(dp,0x3f,sizeof(dp));  
        for(int i=0;i<=n;i++)  
        {  
            dp[i][0]=0;
            dp[i][1]=1;
        }  
        for(int i=0;i<=k;i++)  
        {  
            dp[1][i]=i;  
        }  
        for(int j=2;j<=k;j++)  
        {  
            for(int i=2;i<=n;i++)  
            {  
                for(int t=1;t<=j;t++)	dp[i][j]=min(dp[i][j],max(dp[i-1][t-1],dp[i][j-t])+1);  
            }  
        }  
        printf("%d\n",dp[n][k]);  
    }  
    return 0;  
}  
