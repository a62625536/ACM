#include<bits/stdc++.h>
using namespace std;

int n;
struct xx
{
    int l,r;
    friend bool operator<(xx a,xx b)
    {
        return a.l < b.l;
    }
}a[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i].l >> a[i].r;
    sort(a+1,a+1+n);
    int ans = 0;
    priority_queue< int,vector<int>,greater<int> > q;
    for(int i = 1;i <= n;i++)
    {
        if(q.empty() || a[i].l <= q.top())
        {
            ans++;
            q.push(a[i].r);
        }
        else
        {
            q.pop();
            q.push(a[i].r);
        }
    }
    if(ans > 2) cout << "NO" << endl;
    else    cout << "YES" << endl;
    return 0;
}
