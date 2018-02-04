#include<bits/stdc++.h>
using namespace std;

int n,k,p,a[2005],b[2005];


int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> p;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= k;i++)   cin >> b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+k);
    int ans = INT_MAX;
    for(int i = 1;i+n-1 <= k;i++)
    {
        int maxx = 0;
        for(int j = 1;j <= n;j++)
        {
            int t = i+j-1;
            maxx = max(maxx,abs(a[j]-b[t])+abs(b[t]-p));
        }
        ans = min(ans,maxx);
    }
    cout << ans << endl;
    return 0;
}
