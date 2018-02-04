#include<bits/stdc++.h>
using namespace std;

string s,ss;
int n;
map<char,int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin >> ss >> s >> n;
    for(int i = 0;i < ss.length();i++)  mp[ss[i]] = 1;
    s = ' '+s;
    while(n--)
    {
        cin >> ss;
        ss = ' '+ss;
        int t = ss.length()-s.length()+1,flag = 1;
        if(t < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int i = 1,j = 1;
        for(;i < s.length() && j < ss.length();i++,j++)
        {
            if(s[i] == '?')
            {
                if(!mp.count(ss[j]))    flag = 0;
            }
            else if(s[i] == '*')
            {
                j--;
                while(t--)
                {
                    j++;
                    if(mp.count(ss[j])) flag = 0;
                }
            }
            else if(s[i] != ss[j])  flag = 0;
        }
        if(i < s.length() && s[i] == '*')   i++;
        if(flag && i == s.length() && j == ss.length()) cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}
