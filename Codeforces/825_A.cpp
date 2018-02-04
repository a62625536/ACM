#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> s;
    int now = 0,flag = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == '1') now++,flag = 0;
        else
        {
            cout << now;
            now = 0;
            flag = 1;
        }
    }
    if(now || flag) cout << now;
    cout << endl;
    return 0;
}
