#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,a[200005];
long long fac[100005] = {1};

long long qpow(long long a,long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b%2) ans = ans*a%MOD;
        a = a*a%MOD;
        b /= 2;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    for(int i = 1;i <= 100000;i++)  fac[i] = fac[i-1]*i%MOD;
    cin >> n;
    for(int i = 0;i < n;i++)    cin >> a[i];
    if(n == 1)
    {
        cout << a[0] << endl;
        return 0;
    }
    if(n%2)
    {
        n--;
        int now = 1;
        for(int i = 0; i < n;i++)
        {
            if(now) a[i] = (a[i]+a[i+1])%MOD;
            else    a[i] = (a[i]-a[i+1]+MOD)%MOD;
            now ^= 1;
        }
    }
    n = n/2-1;
    long long ans1 = 0,ans2 = 0;
    for(int i = 0;i <= n;i++)
    {
        long long t = fac[n]*qpow(fac[i]*fac[n-i]%MOD,MOD-2)%MOD;
        ans1 = (ans1+t*a[i*2]%MOD)%MOD;
        ans2 = (ans2+t*a[i*2+1]%MOD)%MOD;
    }
    if(n%2) cout << (ans1-ans2+MOD)%MOD << endl;
    else    cout << (ans1+ans2)%MOD << endl;
    return 0;
}
