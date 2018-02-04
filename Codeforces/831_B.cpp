#include<bits/stdc++.h>
using namespace std;

map<char,char> mp;
string s,s1,s2;
int main()
{
    ios::sync_with_stdio(0);
    cin >> s1 >> s2 >> s;
    for(int i = 0;i < 26;i++)
    {
        mp[s1[i]] = s2[i];
        mp[s1[i]+'A'-'a'] = s2[i]+'A'-'a';
    }
    for(int i = 0;i < s.length();i++)
    {
        if(mp.count(s[i]))  cout << mp[s[i]];
        else    cout << s[i];
    }
    cout << endl;
    return 0;
}
