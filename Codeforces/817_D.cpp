#include<bits/stdc++.h>
using namespace std;

int n,a[1000005],l[1000005],r[1000005];
long long ans = 0;

void f()
{
    for(int i = 1;i <= n;i++)
    {
        l[i] = i-1;
        while(l[i] >= 1 && a[i] > a[l[i]])  l[i] = l[l[i]];
    }
    for(int i = n;i >= 1;i--)
    {
        r[i] = i+1;
        while(r[i] <= n && a[i] >= a[r[i]]) r[i] = r[r[i]];
    }
    for(int i = 1;i <= n;i++)
        ans += (long long)(r[i]-i)*(i-l[i])*a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    f();
    for(int i = 1;i <= n;i++)   a[i] = -a[i];
    f();
    cout << ans << endl;
    return 0;
}
