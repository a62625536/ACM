#include<bits/stdc++.h>
using namespace std;

int n,sex[55],vis[55] = {0};
string s[55];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> sex[i] >> s[i];
    for(int i = 1;i <= n;i++)
    {
        for(int j = n;j >= 1;j--)
        {
            if(!vis[j] && sex[i] != sex[j])
            {
                vis[i] = 1;
                vis[j] = 1;
                cout << s[i] << " " << s[j] << endl;
                break;
            }
        }
    }
    return 0;
}
