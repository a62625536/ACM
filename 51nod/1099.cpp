#include<bits/stdc++.h>
using namespace std;

int n;
struct xx
{
    int x,y;
    friend bool operator<(xx a,xx b)
    {
        return a.x-a.y > b.x-b.y;
    }
}a[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i].x >> a[i].y;
    sort(a+1,a+1+n);
    int ans = 0,now = 0;
    for(int i = 1;i <= n;i++)
    {
        ans = max(ans,now+a[i].x);
        now += a[i].y;
    }
    ans = max(ans,now);
    cout << ans << endl;
    return 0;
}
