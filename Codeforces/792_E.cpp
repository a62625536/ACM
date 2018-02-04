#include<bits/stdc++.h>
using namespace std;

int n,a[505];

bool ok(int x)
{
    if(x == 0)  return 1;
    for(int i = 1;i <= n;i++)
    {
        if(a[i]%x > a[i]/x) return 0;
    }
    return 1;
}

long long f(int x)
{
    long long ans = 0;
    for(int i = 1;i <= n;i++)   ans += a[i]/(x+1)+(a[i]%(x+1) != 0);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    long long ans = 1e18;
    for(int i = 1;i <= sqrt(a[1]);i++)
    {
        if(ok(i))   ans = min(ans,f(i));
        if(ok(a[1]/i)) ans = min(ans,f(a[1]/i));
        if(a[1]%i == 0 && ok(a[1]/i-1))   ans = min(ans,f(a[1]/i-1));
    }
    cout << ans << endl;
    return 0;
}
