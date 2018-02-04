#include<bits/stdc++.h>
using namespace std;

struct xx
{
    double num,price,x;
    friend bool operator<(xx a,xx b)
    {
        return a.x > b.x;
    }
}a[1005];
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i].num;
    for(int i = 1;i <= n;i++)   cin >> a[i].price;
    for(int i = 1;i <= n;i++)   a[i].x = a[i].price/a[i].num;
    sort(a+1,a+1+n);
    double ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(m >= a[i].num)
        {
            m -= a[i].num;
            ans += a[i].price;
        }
        else
        {
            ans += a[i].x*m;
            break;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
