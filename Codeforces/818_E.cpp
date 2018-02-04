#include<bits/stdc++.h>
using namespace std;

int n,k,a[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int b = 0;
    long long now = 1,ans = 0;
    for(int r = 1;r <= n;r++)
    {
        now = now*a[r]%k;
        if(!now)
        {
            int l = r+1;
            long long t = 1;
            while(--l)
            {
                t = t*a[l]%k;
                if(!t) break;
                now = t;
            }
            ans += (long long)(n-r+1)*(l-b);
            b = l;
        }
    }
    cout << ans << endl;
    return 0;
}
