#include<bits/stdc++.h>
using namespace std;

struct xx
{
    int id;
    long long x;
    friend bool operator<(xx a,xx b)
    {
        return a.x < b.x;
    }
}a[50005];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    long long sum = 0;
    for(int i = 1;i <= n;i++)
    {
        long long x;
        cin >> x;
        sum += x;
        a[i].x = sum;
        a[i].id = i;
    }
    a[0].x = 0;
    a[0].id = 0;
    sort(a,a+1+n);
    long long ans = 1e18;
    for(int i = 1;i <= n;i++)
    {
        if(a[i].id > a[i-1].id && a[i].x > a[i-1].x)    ans = min(ans,a[i].x-a[i-1].x);
    }
    cout << ans << endl;
    return 0;
}
