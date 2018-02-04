#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;

int n,m;
string s[100005];
map<string,int> mp;
priority_queue<int> q[100005];

int main()
{
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> s[i] >> x;
        if(!mp[s[i]])   mp[s[i]] = ++cnt;
        q[mp[s[i]]].push(x);
    }
    int ans1 = 0,ans2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int t = mp[s[i]];
        if(q[t].empty())    continue;
        string ss = s[i];
        reverse(ss.begin(),ss.end());
        int tt = mp[ss];
        if(tt == 0 || q[tt].empty())    continue;
        if(t == tt)
        {
            if(q[t].size() == 1)    continue;
            int a = q[t].top();
            q[t].pop();
            int b = q[t].top();
            q[t].pop();
            if(a < 0 || a+b < 0)
            {
                q[t].push(a);
                q[t].push(b);
                continue;
            }
            if(b < 0)   ans2 = max(ans2,-b);
            ans1 += a+b;
        }
        else
        {
            int a = q[t].top(),b = q[tt].top();
            if(a+b < 0) continue;
            ans1 += a+b;
            q[t].pop();
            q[tt].pop();
        }
    }
    for(int i = 1;i <= n;i++)
    {
        int t = mp[s[i]];
        string ss = s[i];
        reverse(ss.begin(),ss.end());
        if(ss != s[i])  continue;
        if(q[t].empty())    continue;
        ans2 = max(ans2,q[t].top());
    }
    cout << ans1+ans2 << endl;
    return 0;
}
