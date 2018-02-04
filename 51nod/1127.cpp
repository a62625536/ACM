#include<bits/stdc++.h>
using namespace std;

string s;
map<char,int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    int ans = 1e9,cnt = 0,l = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(mp[s[i]] == 0)  cnt++;
        mp[s[i]]++;
        while(cnt == 26)
        {
            ans = min(ans,i-l+1);
            mp[s[l]]--;
            if(mp[s[l]] == 0)   cnt--;
            l++;
        }
    }
    if(ans == 1e9)  cout << "No Solution" << endl;
    else    cout << ans << endl;
    return 0;
}
