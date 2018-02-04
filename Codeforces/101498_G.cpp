#include<bits/stdc++.h>
using namespace std;

int n,a[2005];

long long lcm(long long a,long long b)
{
    long long t = __gcd(a,b);
    if(1e14/b > a/t)    return a/t*b;
    return 1e18;
}

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++)   cin >> a[i];
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            long long t = 1,sum = 0;
            for(int j = i;j <= n;j++)
            {
                sum += a[j];
                t = lcm(t,a[j]);
                if(t > 1e14)    break;
                if(sum%t == 0)  ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
