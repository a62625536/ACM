#include<bits/stdc++.h>
using namespace std;

int n,m,k,q,cnt = 0,pre[100005] = {0},l[100005],r[100005],ok[100005] = {0},sum[100005];
vector<int> v[100005];

void dfs(int now)
{
    ++cnt;
    l[now] = cnt;
    sum[now] = 1;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        dfs(t);
        sum[now] += sum[t];
    }
    r[now] = cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    while(k--)
    {
        int x,y;
        cin >> x >> y;
        if(pre[y] != 0)
        {
            v[pre[y]].push_back(x);
            ok[x] = 1;
        }
        pre[y] = x;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!ok[i])  dfs(i);
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        if(pre[y] && l[x] <= l[pre[y]] && r[pre[y]] <= r[x])    cout << sum[x] << endl;
        else    cout << 0 << endl;
    }
    return 0;
}
