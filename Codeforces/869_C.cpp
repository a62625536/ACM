#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long a,b,c,p[5005][5005];

long long f(long long a,long long b)
{
    long long ans = 1,fac = 1;
    for(int i = 1;i <= min(a,b);i++)
    {
        fac = (fac*i)%MOD;
        ans = (ans+p[a][i]*p[b][i]%MOD*fac%MOD)%MOD;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> a >> b >> c;
    p[0][0] = 1;
    for(int i = 1;i <= 5000;i++)
    {
        p[i][0] = 1;
        for(int j = 1;j <= i;j++)   p[i][j] = (p[i-1][j-1]+p[i-1][j])%MOD;
    }
    long long ans = 1;
    ans = ans*f(a,b)%MOD;
    ans = ans*f(a,c)%MOD;
    ans = ans*f(b,c)%MOD;
    cout << ans << endl;
    return 0;
}
