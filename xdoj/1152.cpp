#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

struct st
{
    string name,course;
};
map<int,st> mp;
map<int,st>::iterator it;

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        mp.clear();
        string a,c,d;
        int b;
        cin >> a >> c;
        for(int i = 1;i <= n;i++)
        {
            cin >> a >> b;
            mp[b].name = a;
            mp[b].course = "NULL";
        }
        cin >> a >> c >> d;
        for(int i = 1;i <= m;i++)
        {
            cin >> a >> b >> c;
            mp[b].course = c;
        }
        cout << "Name StuNum CourseName" << endl;
        for(it = mp.begin();it != mp.end();it++)    cout << it->second.name << ' ' << it->first << ' ' << it->second.course << endl;
    }
    return 0;
}
