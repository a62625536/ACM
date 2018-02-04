#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

double f(double x)
{
    double maxx = -1e18,minn = 1e18,now1 = 0,now2 = 0;
    for(int i = 1;i <= n;i++)
    {
        if(now1 >= 0)   now1 += a[i]-x;
        else    now1 = a[i]-x;
        if(now2 <= 0)   now2 += a[i]-x;
        else    now2 = a[i]-x;
        maxx = max(maxx,now1);
        minn = min(minn,now2);
    }
    return max(abs(maxx),abs(minn));
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    double l = -20000,r = 20000;
    for(int i = 1;i <= 100;i++)
    {
        double ll = l+(r-l)/3,rr = r-(r-l)/3;
        if(f(ll) > f(rr))   l = ll;
        else    r = rr;
    }
    cout << fixed << setprecision(10) << f(l) << endl;
    return 0;
}
