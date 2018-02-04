#include<bits/stdc++.h>
using namespace std;

int n,q,ans[128][1505] = {0},cnt[1505];
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> s >> q;
    s = ' '+s;
    for(char c = 'a';c <= 'z';c++)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i = 1;i <= n;i++)
        {
            cnt[i] = cnt[i-1];
            if(s[i] != c)   cnt[i]++;
        }
        for(int i = 0;i <= n;i++)
        {
            for(int j = i+1;j <= n;j++)
            {
                ans[c][cnt[j]-cnt[i]] = max(ans[c][cnt[j]-cnt[i]],j-i);
            }
        }
        for(int i = 1;i <= n;i++)   ans[c][i] = max(ans[c][i-1],ans[c][i]);
    }
    while(q--)
    {
        int x;
        cin >> x >> s;
        cout << ans[s[0]][x] << endl;
    }
    return 0;
}
