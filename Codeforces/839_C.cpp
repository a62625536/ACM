#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v[100005];

double dfs(int now,int pre)
{
    double ans = 1;
    int sz = v[now].size();
    if(now != 1)    sz--;
    for(int i = 0;i < v[now].size();i++)
    {
        int t = v[now][i];
        if(t == pre)    continue;
        ans += dfs(t,now)/sz;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << fixed << setprecision(10) << dfs(1,0)-1 << endl;
    return 0;
}
