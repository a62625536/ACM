#include<bits/stdc++.h>
using namespace std;

int n,a[200005],h[200005];
map<int,int> mp;
vector<int> v[200005];

void dfs(int now)
{
    int x = 0;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        dfs(t);
        x = max(h[t],x);
    }
    h[now] = x+1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 2;i <= n;i++)
    {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    dfs(1);
    int ok = 0,cnt1 = 0;
    for(int i = 1;i <= n;i++)
    {
        if(h[i]%2)
        {
            ok ^= a[i];
            cnt1++;
            mp[a[i]]++;
        }
    }
    int cnt2 = n-cnt1;
    long long ans = 0;
    if(ok == 0) ans = (long long)cnt1*(cnt1-1)/2+(long long)cnt2*(cnt2-1)/2;
    for(int i = 1;i <= n;i++)
    {
        if(h[i]%2 == 0) ans += mp[ok^a[i]];
    }
    cout << ans << endl;
    return 0;
}
