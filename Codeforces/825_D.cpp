#include<bits/stdc++.h>
using namespace std;

string s1,s2;
map<char,int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin >> s1 >> s2;
    for(int i = 0;i < s1.length();i++)  mp[s1[i]]++;
    int now = 0;
    for(int i = 0;i < s1.length();i++)
    {
        if(s1[i] != '?')    continue;
        now = (now+1)%s2.length();
        if(mp[s2[now]])
        {
            mp[s2[now]]--;
            i--;
        }
        else    s1[i] = s2[now];
    }
    cout << s1 << endl;
    return 0;
}
