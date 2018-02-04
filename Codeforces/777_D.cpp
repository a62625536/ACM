#include<bits/stdc++.h>
using namespace std;

int n;
string s[500005];

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> s[i];
    for(int i = n-1;i >= 1;i--)
    {
        if(s[i] > s[i+1])
        {
            int endd = min(s[i].size(),s[i+1].size());
            int j;
            for(j = 1;j < endd && s[i][j] <= s[i+1][j];j++);
            s[i].erase(s[i].begin()+j,s[i].end());
        }
    }
    for(int i = 1;i <= n;i++)   cout << s[i] << endl;
    return 0;
}
