#include<bits/stdc++.h>
using namespace std;

int n,a[50005],ans[50005],sum[50005] = {0};

bool ok(int x)
{
    int t = n/x;
    for(int i = t;i <= n;i += t)
    {
        if(sum[i]-sum[i-t] == 0)    return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 2;i < n;i++)
    {
        sum[i] = sum[i-1];
        if(a[i-1] < a[i] && a[i] > a[i+1])  sum[i]++;
    }
    sum[n] = sum[n-1];
    if(sum[n] == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 1;i*i <= n;i++)
    {
        if(n%i == 0)
        {
            ans[++cnt] = i;
            if(i*i != n)    ans[++cnt] = n/i;
        }
    }
    sort(ans+1,ans+1+cnt);
    int l = 1,r = cnt;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(ok(ans[mid]))    l = mid;
        else    r = mid-1;
    }
    cout << ans[l] << endl;
    return 0;
}
