#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> s;
        if(s.length() <= 10)    cout << s << endl;
        else
        {
            cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
        }
    }
    return 0;
}
