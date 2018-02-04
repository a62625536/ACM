#include<bits/stdc++.h>
using namespace std;

int n,a[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    int t = (n+1)/2;
    long long ans = 0;
    for(int i = 1;i <= n;i++)   ans += abs(a[i]-a[t]);
    cout << ans << endl;
    return 0;
}
