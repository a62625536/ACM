#include<bits/stdc++.h>
using namespace std;

int n,a[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    long long ans = 0;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(x%2 == 0 && x > 0)       ans += x;
        else if(x%2)    a[++cnt] = x;
    }
    sort(a+1,a+1+cnt);
    ans += a[cnt];
    for(int i = cnt-1;i >= 1;i -= 2)
    {
        if(i-1 < 1) break;
        if(a[i]+a[i-1] > 0) ans += a[i]+a[i-1];
    }
    cout << ans << endl;
    return 0;
}
