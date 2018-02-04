#include<bits/stdc++.h>
using namespace std;

int n,m,a[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    int ans = 0;
    int l = 1;
    for(int r = n;r >= l;r--)
    {
        ans++;
        if(l != r && a[l]+a[r] <= m)    l++;
    }
    cout << ans << endl;
    return 0;
}
