#include<bits/stdc++.h>
using namespace std;

int n,m,d[205];
set<int> s[205];

void dfs(int now)
{
    while(s[now].size())
    {
        int t = *s[now].begin();
        s[now].erase(t);
        s[t].erase(now);
        if(now != n+1 && t != n+1)  cout << now << " " << t << endl;
        dfs(t);
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        memset(d,0,sizeof(d));
        while(m--)
        {
            int x,y;
            cin >> x >> y;
            s[x].insert(y);
            s[y].insert(x);
            d[x]++;
            d[y]++;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(d[i]%2)
            {
                s[i].insert(n+1);
                s[n+1].insert(i);
            }
            else    ans++;
        }
        cout << ans << endl;
        for(int i = 1;i <= n;i++)   dfs(i);
    }
    return 0;
}
