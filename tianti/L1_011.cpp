#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;
string s1,s2;

int main()
{
    std::ios::sync_with_stdio(false);
    getline(cin,s1);
    getline(cin,s2);
    for(int i = 0;i < s2.length();i++)  mp[s2[i]] = 1;
    for(int i = 0;i < s1.length();i++)
    {
        if(!mp.count(s1[i]))    cout << s1[i];
    }
    cout << endl;
    return 0;
}
