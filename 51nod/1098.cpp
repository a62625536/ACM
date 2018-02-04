#include<bits/stdc++.h>
using namespace std;

int n,k,a[10005],sum[10005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++)   sum[i] = sum[i-1]+a[i];
    double ans = 1e18;
    for(int l = 1;l+k-1 <= n;l++)
    {
        int r = l+k-1;
        double t = 1.0*(sum[r]-sum[l-1])/k,x = 0;
        for(int i = l;i <= r;i++)   x += (t-a[i])*(t-a[i]);
        ans = min(x,ans);
    }
    cout << (long long)ans << endl;
    return 0;
}
