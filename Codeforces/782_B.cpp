#include<bits/stdc++.h>
using namespace std;

int n;
double x[60005],v[60005];

bool ok(double t)
{
    double l = 1e9,r = 0;
    for(int i = 1;i <= n;i++)
    {
        l = min(l,x[i]+v[i]*t);
        r = max(r,x[i]-v[i]*t);
    }
    if(r-l > 1e-9)  return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> x[i];
    for(int i = 1;i <= n;i++)   cin >> v[i];
    double l = 0,r = 1e9;
    while(abs(l-r) > 1e-7)
    {
        double mid = (l+r)/2;
        if(ok(mid)) l = mid;
        else    r = mid;
    }
    cout << fixed << setprecision(8) << l << endl;
    return 0;
}
