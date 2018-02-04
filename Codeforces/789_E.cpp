#include<bits/stdc++.h>
using namespace std;

struct xx
{
    int x,cnt;
    xx(int a,int b):x(a),cnt(b){};
};
int n,k,has[1005] = {1},vis[1005] = {0};
vector<int> v[1005];
map<int,int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    while(k--)
    {
        int x;
        cin >> x;
        if(x == n)
        {
            cout << 1 << endl;
            return 0;
        }
        has[x] = 1;
        mp[x-n] = 1;
    }
    for(int i = 0;i <= 1000;i++)
    {
        for(int j = 0;j <= 1000;j++)
        {
            if(i == j)  continue;
            if(mp.count(j-i))   v[i].push_back(j);
        }
    }
    queue<xx> q;
    q.push(xx(0,0));
    while(!q.empty())
    {
        int now = q.front().x,cnt = q.front().cnt;
        q.pop();
        if(vis[now])    continue;
        vis[now] = 1;
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i];
            if(t == 0)
            {
                cout << cnt+1 << endl;
                return 0;
            }
            if(vis[t])  continue;
            q.push(xx(t,cnt+1));
        }
    }
    cout << -1 << endl;
    return 0;
}
