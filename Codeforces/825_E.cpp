#include<bits/stdc++.h>
using namespace std;

int n,m,in[200005] = {0},ans[200005];
vector<int> v[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        v[y].push_back(x);
        in[x]++;
    }
    priority_queue<int> q;
    for(int i = 1;i <= n;i++)
    {
        if(!in[i])  q.push(i);
    }
    int cnt = n;
    while(!q.empty())
    {
        int now = q.top();
        q.pop();
        ans[now] = cnt--;
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i];
            if(--in[t] == 0)    q.push(t);
        }
    }
    for(int i = 1;i <= n;i++)   cout << ans[i] << " ";
    cout << endl;
    return 0;
}
