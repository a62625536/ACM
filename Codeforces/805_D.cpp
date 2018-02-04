#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    long long ans = 0,now = 0;
    for(int i = s.length()-1;i >= 0;i--)
    {
        if(s[i] == 'b') now = (now+1)%MOD;
        else
        {
            ans = (ans+now)%MOD;
            now = (now+now)%MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
