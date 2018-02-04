#include<bits/stdc++.h>
using namespace std;

int n,k,a[200005],b[200005];
struct xx
{
    int id,x;
}c[200005];

bool cmp(xx a,xx b)
{
    return a.x < b.x;
}

int main()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)   cin >> b[i];
    for(int i = 1;i <= n;i++)
    {
        c[i].x = a[i]-b[i];
        c[i].id = i;
    }
    sort(c+1,c+1+n,cmp);
    int ans = 0;
    int i;
    for(i = 1;i <= k;i++)   ans += a[c[i].id];
    for(;i <= n;i++)
    {
        if(c[i].x > 0)  break;
        ans += a[c[i].id];
    }
    for(;i <= n;i++)    ans += b[c[i].id];
    cout << ans << endl;
    return 0;
}
