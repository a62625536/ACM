#include<bits/stdc++.h>
using namespace std;

int n,k,a[100005];
map<long long,int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    long long x = 1,ans = 0;
    while(abs(x) <= 1e14)
    {
        mp.clear();
        mp[0]++;
        long long sum = 0;
        for(int i = 1;i <= n;i++)
        {
            sum += a[i];
            ans +=  mp[sum-x];
            mp[sum]++;
        }
        x *= k;
        if(x == 1)  break;
    }
    cout << ans << endl;
    return 0;
}
