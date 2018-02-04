#include<bits/stdc++.h>
using namespace std;

int n,k,a[100005],ne[100005];

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n;i++)   cin >> a[i];
        map<int,int> mp;
        set<int> s;
        for(int i = n;i >= 1;i--)
        {
            if(mp.count(a[i]))  ne[i] = mp[a[i]];
            else    ne[i] = n+i;
            mp[a[i]] = i;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(s.count(i))
            {
                s.erase(i);
                s.insert(ne[i]);
                continue;
            }
            if(s.size() == k)  s.erase(*s.rbegin());
            s.insert(ne[i]);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
