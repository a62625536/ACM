#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[105];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int ans = 1e9;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = m;i >= 1;i--)
    {
        if(a[i] == 0)   continue;
        if(a[i] > k)    continue;
        ans = min(ans,(m-i)*10);
    }
    for(int i = m;i <= n;i++)
    {
        if(a[i] == 0)   continue;
        if(a[i] > k)    continue;
        ans = min(ans,(i-m)*10);
    }
    cout << ans << endl;
    return 0;
}
