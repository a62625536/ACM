#include<bits/stdc++.h>
using namespace std;

int n;
map<int,int> mp;

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        mp.clear();
        cin >> n;
        int ans,maxx = 0;
        for(int i = 1;i <= n;i++)
        {
            string s;
            int x;
            cin >> s >> x;
            mp[x]++;
            if(maxx == mp[x])    ans = min(ans,x);
            else if(maxx < mp[x])
            {
                ans = x;
                maxx = mp[x];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
