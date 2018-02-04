#include<bits/stdc++.h>
using namespace std;

map<char,string> mp;
string s;

int main()
{
    std::ios::sync_with_stdio(false);
    mp['0'] = "ling";
    mp['1'] = "yi";
    mp['2'] = "er";
    mp['3'] = "san";
    mp['4'] = "si";
    mp['5'] = "wu";
    mp['6'] = "liu";
    mp['7'] = "qi";
    mp['8'] = "ba";
    mp['9'] = "jiu";
    mp['-'] = "fu";
    cin >> s;
    cout << mp[s[0]];
    for(int i = 1;i < s.length();i++)   cout << " " << mp[s[i]];
    cout << endl;
    return 0;
}
