#include<bits/stdc++.h>
using namespace std;

int k;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s >> k;
    int i,cnt = 0;
    if(s[0] == '0')
    {
        cout << 0 << endl;
        return 0;
    }
    for(i = s.length()-1;i >= 0;i--)
    {
        if(s[i] == '0')
        {
            cnt++;
            if(cnt == k)    break;
        }
    }
    if(i < 0)   cout << s.length()-1 << endl;
    else    cout << s.length()-i-k << endl;
    return 0;
}
