#include<bits/stdc++.h>
using namespace std;

int n,m,vis[100005];
map<int,string> sex;
vector<int> v[100005];

void dfs1(int now,int cnt)
{
    vis[now] = 1;
    if(cnt <= 4)
    {
        for(int i = 0;i < v[now].size();i++)    dfs1(v[now][i],cnt+1);
    }
}

bool dfs2(int now,int cnt)
{
    if(vis[now])    return 0;
    int flag = 0;
    if(cnt <= 4)
    {
        for(int i = 0;i < v[now].size();i++)
        {
            if(!dfs2(v[now][i],cnt+1))  flag = 1;
        }
    }
    if(flag)    return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int a,b,c;
        string s;
        cin >> a >> s >> b >> c;
        sex[a] = s;
        if(b != -1)
        {
            v[a].push_back(b);
            sex[b] = "M";
        }
        if(c != -1)
        {
            v[a].push_back(c);
            sex[c] = "F";
        }
    }
    cin >> m;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        if(sex[a] == sex[b])    cout << "Never Mind" << endl;
        else
        {
            memset(vis,0,sizeof(vis));
            dfs1(a,1);
            if(dfs2(b,1))   cout << "Yes" << endl;
            else    cout << "No" << endl;
        }
    }
    return 0;
}
