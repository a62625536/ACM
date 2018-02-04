#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char a[1005],b[1005];
int dp[1005][1005] = {0};

int main()
{
    scanf("%s%s",a,b);
    int len1 = strlen(a),len2 = strlen(b);
    for(int i = 0;i <= len1;i++)    dp[i][0] = i;
    for(int i = 0;i <= len2;i++)    dp[0][i] = i;
    for(int i = 1;i <= len1;i++)
    {
        for(int j = 1;j <= len2;j++)
        {
            if(a[i-1] == b[j-1])    dp[i][j] = dp[i-1][j-1];
            else    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
        }
    }
    printf("%d\n",dp[len1][len2]);
    return 0;
}
