#include<bits/stdc++.h>
using namespace std;

int n,vis[100005] = {0},s[100005];
struct xx
{
    long long x,y;
}a[100005];
bool ok(xx a,xx b,xx c)
{
    return (b.y-a.y)*(c.x-b.x) >= (b.x-a.x)*(c.y-b.y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int now = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].x >> a[i].y;
        if(now)
        {
            while(now >= 2 && ok(a[s[now-2]],a[s[now-1]],a[i]))    now--;
            vis[s[now-1]] = 1;
        }
        s[now++] = i;
    }
    int cnt = 0;
    for(int i = 2;i <= n;i++)
    {
        if(vis[i])  cnt++;
    }
    cout << cnt << endl;
    return 0;
}
