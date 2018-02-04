#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

string s;

int main()
{
    cin >> s;
    int ans = 1;
    for(int i = 0;i < s.length();i++)
    {
        int t = 1;
        while(i < s.length() && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U' && s[i] != 'Y')
        {
            t++;
            i++;
        }
        ans = max(ans,t);
    }
    cout << ans << endl;
    return 0;
}
