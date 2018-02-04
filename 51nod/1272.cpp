#include<bits/stdc++.h>
using namespace std;

int n;

struct xx
{
    int x,id;
    friend bool operator<(xx a,xx b)
    {
        if(a.x != b.x)  return a.x < b.x;
        return a.id < b.id;
    }
}a[50005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].x;
        a[i].id = i;
    }
    sort(a+1,a+1+n);
    int now = a[1].id,ans = 0;
    for(int i = 2;i <= n;i++)
    {
        now = min(now,a[i].id);
        ans = max(ans,a[i].id-now);
    }
    cout << ans << endl;
    return 0;
}
