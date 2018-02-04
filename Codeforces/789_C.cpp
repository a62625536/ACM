#include<bits/stdc++.h>
using namespace std;

int n;
long long a[100005],b[100005],c[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int f = 1;
    for(int i = 1;i < n;i++)
    {
        b[i] = abs(a[i]-a[i+1])*f;
        f = -f;
        c[i] = -b[i];
    }
    long long ans = 0,now = 0;
    for(int i = 1;i < n;i++)
    {
        now += b[i];
        if(now > ans)   ans = now;
        if(now < 0) now = 0;
    }
    now = 0;
    for(int i = 2;i < n;i++)
    {
        now += c[i];
        if(now > ans)   ans = now;
        if(now < 0) now = 0;
    }
    cout << ans << endl;
    return 0;
}
