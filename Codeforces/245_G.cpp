#include<bits/stdc++.h>
using namespace std;

int n = 0,m,vis[10005],ans[10005];
map<string,int> mp;
vector<int> v[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> m;
    while(m--)
    {
        string a,b;
        cin >> a >> b;
        if(!mp.count(a))    mp[a] = ++n;
        if(!mp.count(b))    mp[b] = ++n;
        v[mp[a]].push_back(mp[b]);
        v[mp[b]].push_back(mp[a]);
    }
    for(int i = 1;i <= n;i++)
    {
        memset(vis,0,sizeof(vis));
        int maxx = 0,cnt = 0;
        for(int j = 0;j < v[i].size();j++)  vis[v[i][j]] = 1;
        for(int j = 1;j <= n;j++)
        {
            if(i == j || vis[j])    continue;
            int sum = 0;
            for(int k = 0;k < v[j].size();k++)
            {
                if(vis[v[j][k]])    sum++;
            }
            if(sum > maxx)
            {
                maxx = sum;
                cnt = 1;
            }
            else if(sum == maxx)    cnt++;
        }
        ans[i] = cnt;
    }
    cout << n << endl;
    for(auto it = mp.begin();it != mp.end();it++)   cout << it->first << " " << ans[it->second] << endl;
	return 0;
}
