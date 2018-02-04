#include<bits/stdc++.h>
using namespace std;

int n,m,enemy[205],pre[205],vis[205],killl[205],num[205],dis[205],cnt[205];
string s1,s2,ss;
map<string,int> mp1;
map<int,string> mp2;
struct xx
{
    int to,w;
    xx(int a,int b):to(a),w(b){};
    friend bool operator <(xx a,xx b)
    {
        return a.w > b.w;
    }
};
vector<xx> v[205];

void dij()
{
    priority_queue<xx> q;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(num,0,sizeof(num));
    memset(killl,0,sizeof(killl));
    memset(cnt,0,sizeof(cnt));
    num[1] = 1;
    cnt[1] = 1;
    dis[1] = 0;
    q.push(xx(1,0));
    while(!q.empty())
    {
        int now = q.top().to;
        q.pop();
        if(vis[now])    continue;
        vis[now] = 1;
        for(int i = 0;i < v[now].size();i++)
        {
            int t = v[now][i].to,w = v[now][i].w;
            if(vis[t])  continue;
            if(dis[now]+w < dis[t])
            {
                cnt[t] = cnt[now];
                dis[t] = dis[now]+w;
                num[t] = num[now]+1;
                killl[t] = killl[now]+enemy[t];
                q.push(xx(t,dis[t]));
                pre[t] = now;
            }
            else if(dis[now]+w == dis[t])
            {
                cnt[t] += cnt[now];
                if(num[now]+1 > num[t] ||num[now]+1 == num[t] && killl[now]+enemy[t] > killl[t])
                {
                    dis[t] = dis[now]+w;
                    num[t] = num[now]+1;
                    killl[t] = killl[now]+enemy[t];
                    q.push(xx(t,dis[t]));
                    pre[t] = now;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s1 >> ss;
    mp1[s1] = 1;
    mp2[1] = s1;
    for(int i = 2;i <= n;i++)
    {
        cin >> s1 >> enemy[i];
        mp1[s1] = i;
        mp2[i] = s1;

    }
    for(int i = 1;i <= m;i++)
    {
        int x;
        cin >> s1 >> s2 >> x;
        v[mp1[s1]].push_back(xx(mp1[s2],x));
        v[mp1[s2]].push_back(xx(mp1[s1],x));
    }
    dij();
    vector<string> ans;
    string now = ss;
    while(now != mp2[1])
    {
        ans.push_back(now);
        now = mp2[pre[mp1[now]]];
    }
    cout << mp2[1];
    for(int i = ans.size()-1;i >= 0;i--)    cout << "->" << ans[i];
    cout << endl;
    cout << cnt[mp1[ss]] << " " << dis[mp1[ss]] << " " << killl[mp1[ss]] << endl;
    return 0;
}
