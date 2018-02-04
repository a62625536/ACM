#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,dp[1000005] = {0},a[105];

int main()
{
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int endd = sum/2;
    for(int i = 1;i <= n;i++)
    {
        for(int j = endd;j >= a[i];j--)  dp[j] = max(dp[j-a[i]]+a[i],dp[j]);
    }
    printf("%d\n",sum-2*dp[endd]);
    return 0;
}
