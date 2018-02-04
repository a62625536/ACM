#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    int now = 1,ans = 0,ok = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] > '1')  ok = 1;
        if(ok)  s[i] = '1';
    }
    for(int i = s.length()-1;i >= 0;i--)
    {
        if(s[i] == '1') ans += now;
        now *= 2;
    }
    cout << ans << endl;
    return 0;
}
