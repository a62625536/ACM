#include<bits/stdc++.h>
using namespace std;

int n,q,a[100005],dp[100005][355];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int j = 1;j <= 350;j++)
    {
        for(int i = n;i >= 1;i--)
        {
            if(i+a[i]+j > n)    dp[i][j] = 1;
            else    dp[i][j] = dp[i+a[i]+j][j]+1;
        }
    }
    cin >> q;
    while(q--)
    {
        int p,k;
        cin >> p >> k;
        if(k <= 350)    cout << dp[p][k] << endl;
        else
        {
            int cnt = 0;
            while(p <= n)   p = p+a[p]+k,cnt++;
            cout << cnt << endl;
        }
    }
    return 0;
}
