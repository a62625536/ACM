#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,m,cantbe[200005] = {0},vis[200005] = {0},dp[200005],nextt[200005];
vector<int> v[200005];

LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
    int d = a;
    if(!b)
    {
        x = 1;
        y = 0;
    }
    else
    {
        d = ex_gcd(b,a%b,y,x);
        y -= (a/b)*x;
    }
    return d;
}

LL f(LL a,LL b,LL n)
{
    LL d,x,y;
    d = ex_gcd(a,n,x,y);
    x = (x%n+n)%n;
    return (x*b/d)%n;
}

int dfs(int now)
{
    if(dp[now] > 0)    return dp[now];
    dp[now] = v[now].size();
    for(int i = now*2;i < m;i += now)
    {
        if(v[i].size() == 0)    continue;
        int t = dfs(i);
        if(dp[now] < v[now].size()+t)
        {
            dp[now] = t+v[now].size();
            nextt[now] = i;
        }
    }
    return dp[now];
}

int main()
{
    ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        cantbe[x] = 1;
    }
    for(int i = 1;i < m;i++)
    {
        if(!cantbe[i]) v[__gcd(i,m)].push_back(i);
    }
    memset(dp,0,sizeof(dp));
    memset(nextt,-1,sizeof(nextt));
	dfs(1);
	int now =  max_element(dp,dp+m)-dp;
	cout << dp[now]+(cantbe[0] == 0) << endl;
	int last = 1;
	while(now != -1)
    {
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i];
            cout << f(last,t,m) << " ";
            last = t;
        }
        now = nextt[now];
    }
    if(cantbe[0] == 0)   cout << 0 << endl;
    else    cout << endl;
    return 0;
}
