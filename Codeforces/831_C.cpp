#include<bits/stdc++.h>
using namespace std;

int n,k,a[2005],b[2005];
map<int,int> mp,ok;

int main()
{
    ios::sync_with_stdio(0);
    cin >> k >> n;
    for(int i = 1;i <= k;i++)   cin >> a[i];
    for(int i = 2;i <= k;i++)   a[i] += a[i-1];
    for(int i = 1;i <= k;i++)   mp[a[i]] = 1;
    for(int i = 1;i <= n;i++)   cin >> b[i];
    for(int i = n;i >= 1;i--)   b[i] -= b[1];
    int ans = 0;
    for(int i = 1;i <= k;i++)
    {
        int flag = 1;
        for(int j = 1;j <= n;j++)
        {
            if(!mp.count(a[i]+b[j]))
            {
                flag = 0;
                break;
            }
        }
        if(flag && !ok.count(a[i]))
        {
            ans++;
            ok[a[i]] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
