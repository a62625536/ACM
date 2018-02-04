#include<bits/stdc++.h>
using namespace std;

int n,k,a[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        while(k*2 < a[i])
        {
            k *= 2;
            ans++;
        }
        k = max(k,a[i]);
    }
    cout << ans << endl;
    return 0;
}
