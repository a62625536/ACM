#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
string s,ans = "";

int main()
{
    cin >> n >> s;
    for(int i = 0;n > 0;i++,n--)
    {
        if(n&1) ans = ans+s[i];
        else    ans = s[i]+ans;
    }
    cout << ans << endl;
    return 0;
}
