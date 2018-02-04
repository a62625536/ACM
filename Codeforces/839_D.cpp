#include<bits/stdc++.h>
using namespace std;

int n,k,cnt[26] = {0};
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> s;
    for(int i = 0;i < s.length();i++)   cnt[s[i]-'a']++;
    for(int i = 0;i < 26;i++)
    {
        if(cnt[i] > k)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
