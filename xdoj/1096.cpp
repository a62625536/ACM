#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[85][85],n; 

int main()  
{ 
    for(int i = 1;i <= 80;i++)  
    {  
        dp[i][1] = 1;
        dp[1][i] = 1;
    }  
    for(int i = 2;i <= 80;i++)  
    {  
        for(int j = 2;j <= 80;j++)  
        {  
        	if(i == j)	dp[i][j] = dp[i][j-1]+1;
            else if(i < j)	dp[i][j] = dp[i][j-1]; 
            else	dp[i][j] = dp[i-j][j]+dp[i][j-1];
        }  
    }  
    while(~scanf("%d",&n))	printf("%d\n",dp[n][n]-1);
    return 0;  
}  
