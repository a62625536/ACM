#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[1005][1005] = {0},len1,len2;
char a[1005],b[1005];

void lcs()
{
    for(int i = 1; i <= len1;i++)
    {
        for(int j = 1;j <= len2;j++)
        {
            if(a[i-1] == b[j-1])    dp[i][j] = dp[i-1][j-1]+1;
            else    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

void printflcs(int x,int y)
{
    if(x == 0 || y == 0)    return;
    if(a[x-1] == b[y-1])
    {
        printflcs(x-1,y-1);
        printf("%c",a[x-1]);
    }
    else if(dp[x][y-1] > dp[x-1][y])    printflcs(x,y-1);
    else    printflcs(x-1,y);
}

int main()
{
    scanf("%s%s",a,b);
    len1 = strlen(a);
    len2 = strlen(b);
    lcs();
    printflcs(len1,len2);
    printf("\n");
    return 0;
}
