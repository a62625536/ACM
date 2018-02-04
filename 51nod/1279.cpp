#include<bits/stdc++.h>
using namespace std;

int n,m,a[50005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    cin >> a[1];
    for(int i = 2;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] > a[i-1])   a[i] = a[i-1];
    }
    int now = n,ans = 0;
    for(int i = 1;i <= m;i++)
    {
        int x;
        cin >> x;
        int l = 0,r = now;
        while(l < r)
        {
            int mid = (l+r+1)/2;
            if(a[mid] >= x) l = mid;
            else    r = mid-1;
        }
        if(l > 0)   ans++;
        now = l-1;
    }
    cout << ans << endl;
    return 0;
}
