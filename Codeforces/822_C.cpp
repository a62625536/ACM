#include<bits/stdc++.h>
using namespace std;

int n,x;
map<int,int> mp;
struct xx
{
    int l,r,c;
    friend bool operator <(xx a,xx b)
    {
        return a.l < b.l;
    }
}a[200005];
struct yy
{
    int r,len,c;
    yy(int a,int b,int cc):r(a),len(b),c(cc){};
    friend bool operator <(yy a,yy b)
    {
        return a.r > b.r;
    }
};
priority_queue<yy> q;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> x;
    for(int i = 1;i <= n;i++)   cin >> a[i].l >> a[i].r >> a[i].c;
    sort(a+1,a+1+n);
    int ans = 2e9+5;
    for(int i = 1;i <= n;i++)
    {
        while(!q.empty() && q.top().r < a[i].l)
        {
            if(!mp.count(q.top().len))  mp[q.top().len] = q.top().c;
            else    mp[q.top().len] = min(mp[q.top().len],q.top().c);
            q.pop();
        }
        int len = a[i].r-a[i].l+1;
        if(mp.count(x-len)) ans = min(ans,a[i].c+mp[x-len]);
        q.push(yy(a[i].r,len,a[i].c));
    }
    if(ans == 2e9+5)    cout << -1 << endl;
    else    cout << ans << endl;
    return 0;
}
