#include<bits/stdc++.h>
using namespace std;

int n,k,a[105];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int ans = 0,now = 0;
    for(int i = 1;i <= n;i++)
    {
        now += a[i];
        if(now > 8)
        {
            now -= 8;
            ans += 8;
        }
        else
        {
            ans += now;
            now = 0;
        }
        if(ans >= k)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
