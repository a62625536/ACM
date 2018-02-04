#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

string a,b;
int dp[1005][1005];

int main()
{
    cin >> a;
    b = a;
    reverse(b.begin(),b.end());
    for(int i = 1;i <= a.length();i++)
    {
        for(int j = 1;j <= b.length();j++)
        {
            if(a[i-1] == b[j-1])    dp[i][j] = dp[i-1][j-1]+1;
            else    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    printf("%d\n",a.length()-dp[a.length()][a.length()]);
    return 0;
}
