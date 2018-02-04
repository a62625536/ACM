#include<bits/stdc++.h>
using namespace std;

int n;
struct xx
{
    int x,t;
    friend bool operator<(xx a,xx b)
    {
        return a.t > b.t;
    }
}a[50005];
priority_queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i].t >> a[i].x;
    sort(a+1,a+1+n);
    long long ans = 0;
    int now = 1;
    for(int i = 1e9;i >= 1;i--)
    {
        while(now <= n && a[now].t >= i)    q.push(a[now++].x);
        if(!q.empty())
        {
            ans += q.top();
            q.pop();
        }
        if(q.empty())   i = a[now].t+1;
    }
    cout << ans << endl;
    return 0;
}
