#include<bits/stdc++.h>
using namespace std;

int n,a[200005],ans[200005];
struct xx
{
    int x,id;
    friend bool operator <(xx a,xx b)
    {
        return a.x > b.x;
    }
}b[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        cin >> b[i].x;
        b[i].id = i;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i = 1;i <= n;i++)   ans[b[i].id] = a[i];
    for(int i = 1;i <= n;i++)   cout << ans[i] << " ";
    cout << endl;
    return 0;
}
