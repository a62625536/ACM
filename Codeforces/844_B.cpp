#include<bits/stdc++.h>
using namespace std;

int n,m,a[55][55];

long long c(int x)
{
    long long ans = 1;
    for(int i = 1;i <= x;i++)   ans *= 2;
    return ans-1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >>m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)   cin >> a[i][j];
    }
    long long ans = -n*m;
    for(int i = 1;i <= n;i++)
    {
        int cnt = 0;
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] == 1)    cnt++;
        }
        ans += c(cnt);
        ans += c(m-cnt);
    }
    for(int i = 1;i <= m;i++)
    {
        int cnt = 0;
        for(int j = 1;j <= n;j++)
        {
            if(a[j][i] == 1)    cnt++;
        }
        ans += c(cnt);
        ans += c(n-cnt);
    }
    cout << ans << endl;
    return 0;
}
