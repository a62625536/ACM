#include<bits/stdc++.h>
using namespace std;

int n,ans[200005] = {0};
vector<int> v[200005];

void dfs(int now,int pre)
{
    int c = 1;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        while(c == ans[now] || c == ans[pre])   c++;
        ans[t] = c;
        dfs(t,now);
        c++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ans[1] = 1;
    dfs(1,0);
    int maxx = 0;
    for(int i = 1;i <= n;i++)   maxx = max(maxx,ans[i]);
    cout << maxx << endl;
    for(int i = 1;i <= n;i++)   cout << ans[i] << " ";
    cout << endl;
    return 0;
}
