#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,a[25];

long long qpower(long long a, long long b, long long c)
{
    long long ans = 1;
    a = a%c;
    while(b)
    {
        if(b%2)    ans = ans*a%c;
        a = a*a%c;
        b /= 2;
    }
    return ans;
}

bool ok(long long x)
{
    long long t = 0;
    for(int i = 0;i <= n;i++)   t = (t+a[i]*qpower(x,n-i,MOD)+MOD)%MOD;
    return t == 0;
}

int main()
{
    ios::sync_with_stdio(0);
    a[0] = 1;
    while(cin >> n)
    {
        for(int i = 1;i <= n;i++)   cin >> a[i];
        long long x = abs(a[n]),ans = 0;
        for(long long i = 1;i*i <= x;i++)
        {
            if(x%i) continue;
            if(ok(i))   ans += i;
            if(ok(-i))  ans -= i;
            if(i*i == x)    continue;
            if(ok(x/i)) ans += x/i;
            if(ok(-x/i))    ans -= x/i;
        }
        cout << fixed << setprecision(2) << (double)ans << endl;
    }
    return 0;
}
