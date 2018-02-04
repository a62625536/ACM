#include<bits/stdc++.h>
using namespace std;

int n,a,b,h[15],ansx = 1e9;

void dfs(int now,int num)
{
    if(now == n)
    {
        ansx = min(ansx,num);
        return;
    }
    if(h[now-1] < 0)    dfs(now+1,num);
    int t = 0;
    if(h[now-1] >= 0)
    {
        t = h[now-1]/b+1;
        h[now-1] -= b*t;
        h[now] -= a*t;
        h[now+1] -= b*t;
        dfs(now+1,num+t);
        h[now-1] += b*t;
        h[now] += a*t;
        h[now+1] += b*t;
    }
    int t1 = h[now]/a+1;
    for(int i = t+1;i <= t1;i++)
    {
        h[now-1] -= b*i;
        h[now] -= a*i;
        h[now+1] -= b*i;
        dfs(now+1,num+i);
        h[now-1] += b*i;
        h[now] += a*i;
        h[now+1] += b*i;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> a >> b;
    for(int i = 1;i <= n;i++)   cin >> h[i];
    int ans = 0;
    int t = h[1]/b+1;
    ans += t;
    h[1] -= b*t;
    h[2] -= a*t;
    h[3] -= b*t;
    if(h[n] >= 0)
    {
        t = h[n]/b+1;
        ans += t;
        h[n] -= b*t;
        h[n-1] -= a*t;
        h[n-2] -= b*t;
    }
    dfs(2,0);
    if(ansx == 1e9) ansx = 0;
    cout << ansx+ans << endl;
    return 0;
}
