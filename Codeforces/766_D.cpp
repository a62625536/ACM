#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

map<string,int> mp;
int n,m,q;
int pre[100005],rel[100005] = {0};

int findd(int x)
{
    if(pre[x] == x) return x;
    int p = pre[x];
    pre[x] = findd(pre[x]);
    rel[x] = (rel[x]+rel[p])%2;
    return pre[x];
}

int main()
{
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        mp[s] = i;
    }
    for(int i = 1;i <= n;i++)   pre[i] = i;
    while(m--)
    {
        int x;
        string s1,s2;
        cin >> x >> s1 >> s2;
        int a = findd(mp[s1]),b = findd(mp[s2]);
        if(a != b)
        {
            cout << "YES" << endl;
            pre[b] = a;
            rel[b] = (rel[mp[s1]]-rel[mp[s2]]+x+1)%2;
        }
        else
        {
            int t = (rel[mp[s1]]-rel[mp[s2]]+2)%2+1;
            if(t == x)  cout << "YES" << endl;
            else    cout << "NO" << endl;
        }
    }
    while(q--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int a = findd(mp[s1]),b = findd(mp[s2]);
        if(a != b)  cout << 3 << endl;
        else    cout << (rel[mp[s1]]-rel[mp[s2]]+2)%2+1 << endl;
    }
    return 0;
}
