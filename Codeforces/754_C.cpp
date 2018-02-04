#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

int n,m,cnt[105],vis[105],ok[105][105];
string s[105],ss[105];
map<string,int> mp;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        cnt[0] = 2;
        memset(ok,0,sizeof(ok));
        mp.clear();
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> s[i];
            mp[s[i]] = i;
        }
        cin >> m;
        getchar();
        for(int i = 1;i <= m;i++)   getline(cin,ss[i]);
        for(int i = 1;i <= m;i++)
        {
            memset(vis,0,sizeof(vis));
            int t = ss[i].find(':');
            string now = ss[i].substr(0,t);
            if(now != "?")
            {
                if(cnt[i-1] > 1 || !ok[i-1][mp[now]])
                {
                    cnt[i] = 1;
                    ok[i][mp[now]] = 1;
                }
                continue;
            }
            else
            {
                now = "";
                for(int j = t+1;j < ss[i].length();j++)
                {
                    if(ss[i][j] >= '0' && ss[i][j] <= '9' || ss[i][j] >= 'a' && ss[i][j] <= 'z' || ss[i][j] >= 'A' && ss[i][j] <= 'Z')
                    {
                        now.append(1,ss[i][j]);
                    }
                    else
                    {
                        if(mp[now]) vis[mp[now]] = 1;
                        now = "";
                    }
                }
                if(mp[now]) vis[mp[now]] = 1;
                for(int j = 1;j <= n;j++)
                {
                    if(!vis[j] && (cnt[i-1] > 1 || !ok[i-1][j]))
                    {
                        ok[i][j] = 1;
                        cnt[i]++;
                    }
                }
            }
        }
        vector<string> v;
        for(int i = m;i >= 1;i--)
        {
            ss[i].erase(0,ss[i].find(':'));
            for(int j = 1;j <= n;j++)
            {
                if(ok[i][j])
                {
                    v.push_back(s[j]+ss[i]);
                    ok[i-1][j] = 0;
                    break;
                }
            }
        }
        if(v.size() != m)   cout << "Impossible" << endl;
        else
        {
            for(int i = v.size()-1;i >= 0;i--)  cout << v[i] << endl;
        }
    }
    return 0;
}
