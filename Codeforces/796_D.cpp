#include<bits/stdc++.h>
using namespace std;

struct xx
{
    int id,to;
    xx(int a,int b):id(a),to(b){};
};
int n,k,d,ok[300005] = {0},a[300005],vis[300005] = {0};
vector<xx> v[300005];
vector<int> ans;
struct xxx
{
    int to,pre;
    xxx(int a,int b):to(a),pre(b){};
};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k >> d;
    queue<xxx> q;
    for(int i = 1;i <= k;i++)
    {
        int x;
        cin >> x;
        ok[x] = 1;
        q.push(xxx(x,-1));
    }
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(xx(i,y));
        v[y].push_back(xx(i,x));
    }
    int k = -1;
    for(int i = 1;i <= n;i++)
    {
        if(ok[i])   k++;
    }
    while(!q.empty())
    {
        int now = q.front().to,pre = q.front().pre;
        q.pop();
        if(vis[now])    continue;
        vis[now] = 1;
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i].to,id = v[now][i].id;
            if(t == pre)    continue;
            if(vis[t])
            {
                ans.push_back(id);
                continue;
            }
            q.push(xxx(t,now));
        }
    }
    cout << k << endl;
    for(int i = 0;i < ans.size();i++)   cout << ans[i] << " ";
    cout << endl;
    return 0;
}
