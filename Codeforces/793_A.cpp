#include<bits/stdc++.h>
using namespace std;

int n,k,a[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int minn = 2e9;
    for(int i = 1;i <= n;i++)   minn = min(a[i],minn);
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if((a[i]-minn)%k)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += (a[i]-minn)/k;
    }
    cout << ans << endl;
    return 0;
}
