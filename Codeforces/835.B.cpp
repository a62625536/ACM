#include<bits/stdc++.h>
using namespace std;

int k,cnt[10];
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> k >> s;
    int sum = 0;
    for(int i = 0;i < s.length();i++)
    {
        sum += s[i]-'0';
        cnt[9-s[i]+'0']++;
    }
    int ans = 0,now = 9;
    while(sum < k)
    {
        while(cnt[now] == 0)    now--;
        cnt[now]--;
        sum += now;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
