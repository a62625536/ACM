#include<bits/stdc++.h>
using namespace std;

string s;
int vis[105] = {0};

int main()
{
    ios::sync_with_stdio(false);
	cin >> s;
	int ans = 0;
	for(int i = 1;i < s.length();i++)
    {
        if(vis[i-1] || vis[i])  continue;
        if(s[i-1] == 'V' && s[i] == 'K')
        {
            ans++;
            vis[i-1] = 1;
            vis[i] = 1;
        }
    }
    for(int i = 1;i < s.length();i++)
    {
        if(vis[i-1] || vis[i])  continue;
        if(s[i-1] == 'V' || s[i] == 'K')
        {
            ans++;
            break;
        }
    }
    cout << ans << endl;
	return 0;
}
