#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        ans += a[i]/m;
        if(a[i]%m)  ans++;
    }
    cout << ans/2+ans%2 << endl;
    return 0;
}
