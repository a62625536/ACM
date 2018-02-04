#include<bits/stdc++.h>
using namespace std;

int n,b[1005];
struct xx
{
    int x,y;
    long long v;
    xx(){};
    xx(int a,int b,long long c):x(a),y(b),v(c){};
    friend bool operator<(xx a,xx b)
    {
        return a.v < b.v;
    }
}a[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >>  b[i];
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            a[++cnt].v = b[i]+b[j];
            a[cnt].x = i;
            a[cnt].y = j;
        }
    }
    sort(a+1,a+cnt+1);
    for(int i = 1;i <= cnt;i++)
    {
        int t = lower_bound(a+i+1,a+cnt+1,xx(0,0,-a[i].v))-a;
        if(t <= cnt && a[t].v == -a[i].v && a[t].x != a[i].x && a[t].y != a[i].y && a[t].x != a[i].y && a[t].y != a[i].x)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
