#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define LL long long
#define INF 1e18
using namespace std;

int n,a[200005];
vector<int> v[200005];
LL ans = -INF,sum[200005],dp[200005];

void dfs(int now,int pre)
{
    LL max1 = -INF,max2 = -INF;
    dp[now] = -INF;
    sum[now] = a[now];
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        dfs(t,now);
        sum[now] += sum[t];
        if(dp[t] > max2)   max2 = dp[t];
        if(max2 > max1) swap(max1,max2);
    }
    dp[now] = max(max1,sum[now]);
    if(max2 != -INF)    ans = max(ans,max1+max2);
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    if(ans == -INF) cout << "Impossible" << endl;
    else    cout << ans << endl;
}
