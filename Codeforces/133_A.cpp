#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
