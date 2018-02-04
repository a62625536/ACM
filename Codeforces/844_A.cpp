#include<bits/stdc++.h>
using namespace std;

string s;
int n;
map<char,int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin >> s >> n;
    int cnt = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(mp[s[i]] == 0)   cnt++;
        mp[s[i]] = 1;
    }
    if(s.length() < n)    cout << "impossible" << endl;
    else cout << max(0,n-cnt) << endl;
    return 0;
}
