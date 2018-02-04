#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

string s1,s2;
int a[128] = {0};
string ans[15][2];

int main()
{
    cin >> s1 >> s2;
    int cnt = 0;
    for(int i = 0;i < s1.length();i++)
    {
        if(s1[i] != s2[i])
        {
            if(a[s1[i]] == s2[i] && a[s2[i]] == s1[i])  continue;
            else if(a[s1[i]] || a[s2[i]])
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                cnt++;
                a[s1[i]] = s2[i];
                a[s2[i]] = s1[i];
                ans[cnt][0] = s1[i];
                ans[cnt][1] = s2[i];
            }
        }
    }
    for(int i = 0;i < s1.length();i++)
    {
        if(a[s1[i]])    s1[i] = a[s1[i]];
    }
    if(s1 != s2)
    {
        cout << - 1 << endl;
        return 0;
    }
    cout << cnt << endl;
    for(int i = 1;i <= cnt;i++)   cout << ans[i][0] << " " << ans[i][1] << endl;
    return 0;
}
