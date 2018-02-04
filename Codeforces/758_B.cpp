#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

map<char,int> mp;
int ans[4] = {0};
string s;

int main()
{
    cin >> s;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] != '!') mp[s[i]] = i%4;
    }
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '!') ans[i%4]++;
    }
    cout << ans[mp['R']] << " " << ans[mp['B']] << " " << ans[mp['Y']] << " " << ans[mp['G']] << endl;
    return 0;
}
