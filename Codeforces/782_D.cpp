#include<bits/stdc++.h>
using namespace std;

int n;
string s1[1005],s2[1005];
set<string> was,ban;
vector<string> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string x,y;
        cin >> x >> y;
        s1[i] = x.substr(0,3);
        s2[i] = x.substr(0,2)+y[0];
        if(was.find(s2[i]) != was.end())
        {
            if(was.find(s1[i]) != was.end() || ban.find(s1[i]) != ban.end())
            {
                cout << "NO" << endl;
                return 0;
            }
            was.insert(s1[i]);
            ans.push_back(s1[i]);
        }
        else
        {
            was.insert(s2[i]);
            ban.insert(s1[i]);
            ans.push_back(s2[i]);
        }
    }
    cout << "YES" << endl;
    for(int i = 0;i < n;i++)    cout << ans[i] << endl;
    return 0;
}
