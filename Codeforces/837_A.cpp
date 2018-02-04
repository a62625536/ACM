#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    getchar();
    getline(cin,s);
    int ans = 0,maxx = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == ' ') maxx = 0;
        else
        {
            if(s[i] >= 'A' && s[i] <= 'Z') maxx++;
            ans = max(ans,maxx);
        }
    }
    cout << ans << endl;
    return 0;
}
