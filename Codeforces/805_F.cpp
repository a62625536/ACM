#include<bits/stdc++.h>
using namespace std;

int n,m,q,d[100005] = {0},dd[100005],D[100005],pre[100005];
vector<int> v[100005],vv[100005];
vector<long long> s[100005];
map<int,double> mp[100005];

int findd(int x)
{
    return x == pre[x]?x:pre[x] = findd(pre[x]);
}

void join(int x,int y)
{
    int xx = findd(x),yy = findd(y);
    if(xx != yy)    pre[xx] = yy;
}

void dfs1(int now,int pre)
{
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        dfs1(t,now);
        d[now] = max(d[now],d[t]+1);
    }
}
void dfs2(int now,int pre)
{
    int max1 = -1,max2 = -1;
    dd[now] = d[now];
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(d[t] > max1)
        {
            max2 = max1;
            max1 = d[t];
        }
        else    max2 = max(max2,d[t]);
    }
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        int x = d[now],y = d[t];
        if(d[t] == max1)    d[now] = max2+1;
        else    d[now] = max1+1;
        d[t] = max(d[t],d[now]+1);
        dfs2(t,now);
        d[now] = x;
        d[t] = y;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++)   pre[i] = i;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        join(x,y);
    }
    for(int i = 1;i <= n;i++)
    {
        if(findd(i) == i)
        {
            dfs1(i,-1);
            dfs2(i,-1);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        D[findd(i)] = max(D[findd(i)],dd[i]);
        vv[findd(i)].push_back(dd[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        if(vv[i].size() == 0)   continue;
        sort(vv[i].begin(),vv[i].end());
        s[i].resize(vv[i].size());
        s[i][0] = vv[i][0];
        for(int j = 1;j < s[i].size();j++)
        {
            s[i][j] = s[i][j-1]+vv[i][j];
        }
    }
    while(q--)
    {
        int xx,yy;
        cin >> xx >> yy;
        int x = findd(xx),y = findd(yy);
        if(x == y)
        {
            cout << -1 << endl;
            continue;
        }
        if(vv[x].size() > vv[y].size() || vv[x].size() == vv[y].size() && x > y)    swap(x,y);
        if(mp[x].count(y))
        {
            cout << fixed << setprecision(9) << mp[x][y] << endl;
            continue;
        }
        double ans = 0;
        int maxx = max(D[x],D[y]);
        for(int i = 0;i < vv[x].size();i++)
        {
            int pos = upper_bound(vv[y].begin(),vv[y].end(),maxx-vv[x][i]-1)-vv[y].begin();
            ans += (long long)pos*maxx;
            ans += (long long)(vv[y].size()-pos)*(vv[x][i]+1);
            ans += (long long)s[y][s[y].size()-1];
            if(pos > 0) ans -= (long long)s[y][pos-1];
        }
        ans = ans/vv[x].size()/vv[y].size();
        mp[x][y] = ans;
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
