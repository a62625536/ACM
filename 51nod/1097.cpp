#include<bits/stdc++.h>
using namespace std;

int n;
string s[10005];

bool cmp(string a,string b)
{
    return a+b < b+a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> s[i];
    sort(s+1,s+1+n,cmp);
    string ans = s[1];
    for(int i = 2;i <= n;i++)   ans.append(s[i]);
    int now = 0;
    for(int i = 0;i < ans.length();i++)
    {
        now++;
        cout << ans[i];
        if(now == 1000)
        {
            cout << endl;
            now = 0;
        }
    }
    cout << endl;
    return 0;
}
