#include<bits/stdc++.h>
using namespace std;

int n,p,a[100005],b[100005];

bool ok(double x)
{
    double sum = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i]*x > b[i])   sum += a[i]*x-b[i];
    }
    if(sum < p*x)   return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
	cin >> n >> p;
	long long sum = 0;
	for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if(sum <= p)
    {
        cout << -1 << endl;
        return 0;
    }
    double l = 0,r = 1e18;
    while(abs(l-r) > 1e-5)
    {
        double mid = (l+r)/2;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
	return 0;
}
