#include<bits/stdc++.h>
using namespace std;

int n,k;
struct xx
{
    int id,x,cnt;
    friend bool operator <(xx a,xx b)
    {
        if(a.x != b.x) return a.x > b.x;
        if(a.cnt != b.cnt)  return a.cnt > b.cnt;
        return a.id < b.id;
    }
}a[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        a[i].x = 0;
        a[i].cnt = 0;
        a[i].id = i;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> k;
        while(k--)
        {
            int x,v;
            cin >> x >> v;
            a[x].x += v;
            a[x].cnt++;
            a[i].x -= v;
        }
    }
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++)   cout << a[i].id << " " << fixed << setprecision(2) << (double)a[i].x/100 << endl;
    return 0;
}
