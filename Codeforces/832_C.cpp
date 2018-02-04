#include<bits/stdc++.h>
using namespace std;

int n;
long long s;
struct xx
{
    long long x,v,d;
}a[100005];

bool ok(double t)
{
    long long l1 = 1000001,r1 = 0,l2 = 1000001,r2 = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i].d == 1)
        {
            if(a[i].v*t >= a[i].x)
            {
                l1 = 0;
                r1 = 1000000;
            }
            else if((a[i].v+s)*t >= a[i].x)
            {
                l1 = min(l1,a[i].x);
                r1 = max(r1,a[i].x+(long long)((s*t+a[i].v*t-a[i].x)*(s-a[i].v))/s);
            }
        }
        else
        {
            if(a[i].v*t >= 1000000-a[i].x)
            {
                l2 = 0;
                r2 = 1000000;
            }
            else if((a[i].v+s)*t >= 1000000-a[i].x)
            {
                r2 = max(r2,a[i].x);
                l2 = min(l2,a[i].x-(long long)((s*t+a[i].v*t-1000000+a[i].x)*(s-a[i].v))/s);
            }
        }
    }
    if(l1 > r2 || l2 > r1)  return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> s;
    for(int i = 1;i <= n;i++)   cin >> a[i].x >> a[i].v >> a[i].d;
    double l = 0,r = 1000000;
    for(int i = 1;i <= 100;i++)
    {
        double mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else    l = mid;
    }
    cout << fixed << setprecision(10) << l << endl;
    return 0;
}
