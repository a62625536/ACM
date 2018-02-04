#include<bits/stdc++.h>
using namespace std;

int n,a[200005],ans[200005] = {0};
vector<int> v[200005];
set<int> s[200005];

void dfs(int now,int pre)
{
    for(int t : s[pre]) s[now].insert(__gcd(t,a[now]));
    a[now] = __gcd(a[pre],a[now]);
    s[now].insert(a[pre]);
    for(int t : s[now]) ans[now] = max(ans[now],t);
    for(int t : v[now])
    {
        if(t == pre)    continue;
        dfs(t,now);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    a[0] = 0;
    s[0].insert(0);
    dfs(1,0);
    for(int i = 1;i <= n;i++)   cout << ans[i] << " ";
    cout << endl;
    return 0;
}
