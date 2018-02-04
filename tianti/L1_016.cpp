#include<bits/stdc++.h>
using namespace std;

int n,vis[105] = {0},x[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char m[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
string s[105];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        int sum = 0;
        for(int j = 0;j < 17;j++)   sum += (s[i][j]-'0')*x[j];
        sum %= 11;
        if(m[sum] != s[i][17])
        {
            cnt++;
            vis[i] = 1;
        }
    }
    if(cnt == 0)    cout << "All passed" << endl;
    else
    {
        for(int i = 1;i <= n;i++)
        {
            if(vis[i])  cout << s[i] << endl;
        }
    }

    return 0;
}
