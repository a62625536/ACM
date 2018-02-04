#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,b[15]={0,1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[100005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    dp[0] = 1;
    for(int i = 1;i <= 13;i++)
    {
        for(int j = b[i];j <= n;j++)
        {
            dp[j] = (dp[j]+dp[j-b[i]])%MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
