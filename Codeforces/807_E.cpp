#include<bits/stdc++.h>
using namespace std;

int n,now = 0,num[65] = {0},two[65] = {0},ans[100005];

bool ok(int x)
{
    int t = two[0]-x;
    for(int i = 1;i <= now;i++)
    {
        if(x >= two[i])
        {
            t -= min(x-two[i],t);
            x = two[i];
        }
        else    t += two[i]-x;
        t += num[i];
    }
    if(t <= x)  return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    long long t = 1;
    for(int i = 1;i <= n;i++)
    {
        long long x;
        cin >> x;
        if(x == t)  two[now]++;
        else if(x < t)  num[now-1]++;
        else
        {
            while(t < x)
            {
                t *= 2;
                now++;
            }
            if(x == t)  two[now]++;
            else    num[now-1]++;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= two[0];i++)
    {
        if(ok(i))   ans[++cnt] = i;
    }
    if(cnt == 0)    cout << -1 << endl;
    else
    {
        for(int i = 1;i <= cnt;i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
