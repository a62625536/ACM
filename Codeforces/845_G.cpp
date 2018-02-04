 #include<bits/stdc++.h>
using namespace std;

int n,m,a[100005],vis[100005] = {0};
struct xx
{
    int to,w;
    xx(int a,int b):to(a),w(b){};
};
vector<xx> v[100005];
vector<int> vv;

void add(int x)
{
    for(int i = 0;i < vv.size();i++)    x = min(x,x^vv[i]);
    if(x)   vv.push_back(x);
}

void dfs(int now,int val)
{
    vis[now] = 1;
    a[now] = val;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i].to,w = v[now][i].w;
        if(vis[t])  add(val^w^a[t]);
        else    dfs(t,w^val);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    while(m--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].push_back(xx(y,z));
        v[y].push_back(xx(x,z));
    }
    dfs(1,0);
    for(int i = 0;i < vv.size();i++)    a[n] = min(a[n],a[n]^vv[i]);
    cout << a[n] << endl;
    return 0;
}
