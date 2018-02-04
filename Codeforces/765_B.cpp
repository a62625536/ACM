#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int a[30],vis[30];
string s;

int main()
{
    cin >> s;
    int cnt = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(!vis[s[i]-'a'])
        {
            a[s[i]-'a'] = i;
            vis[s[i]-'a'] = 1;
            cnt++;
        }
    }
    if(cnt == 1 && s[0] != 'a')
    {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 1;i < cnt;i++)
    {
        if(a[i-1] >= a[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
