#include<bits/stdc++.h>
using namespace std;

int n,m,k,q,mp[505][505];
struct xx
{
    int x,y,t;
    friend bool operator<(xx a,xx b)
    {
        return a.t < b.t;
    }
}a[250005];

bool ok(int t)
{
    memset(mp,0,sizeof(mp));
    for(int i = 1;i <= q && a[i].t <= t;i++)  mp[a[i].x][a[i].y] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)   mp[i][j] += mp[i][j-1]+mp[i-1][j]-mp[i-1][j-1];
    }
    for(int i = 1;i <= n-k+1;i++)
    {
        for(int j = 1;j <= m-k+1;j++)
        {
            int endx = i+k-1,endy = j+k-1;
            if(mp[endx][endy]-mp[i-1][endy]-mp[endx][j-1]+mp[i-1][j-1] == k*k)  return 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    for(int i = 1;i <= q;i++)   cin >> a[i].x >> a[i].y >> a[i].t;
    sort(a+1,a+1+q);
    int l = 0,r = 1e9+5;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else    l = mid+1;
    }
    if(l == 1e9+5)  cout << -1 << endl;
    else    cout << l << endl;
    return 0;
}
