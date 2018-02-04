#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 1;i <= n/2+(n&1);i++)
    {
        for(int j = 1;j <= n;j++)   cout << s[0];
        cout << endl;
    }
    return 0;
}
