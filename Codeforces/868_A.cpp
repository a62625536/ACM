#include<bits/stdc++.h>
using namespace std;

int n;
string s,a[105];

int main()
{
    ios::sync_with_stdio(0);
    cin >> s >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == s)
        {
            cout << "YES" << endl;
            return 0;
        }
        for(int j = 1;j <= n;j++)
        {
            if(a[i][1] == s[0] && a[j][0] == s[1])
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
