#include<bits/stdc++.h>
using namespace std;

int n,m;
string s[105];
char ans[5] = "BW";

int main()
{
    ios::sync_with_stdio();
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        s[i] = " "+s[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i][j] == '.') cout << ans[(i+j)%2];
            else    cout << "-";
        }
        cout << endl;
    }
    return 0;
}
