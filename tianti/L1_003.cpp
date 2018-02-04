#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;
string s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> s;
    for(int i = 0;i < s.length();i++)   mp[s[i]]++;
    for(char i = '0';i <= '9';i++)
    {
        if(mp.count(i)) cout << i << ":" << mp[i] << endl;
    }
    return 0;
}
