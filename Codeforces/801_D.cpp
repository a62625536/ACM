#include<bits/stdc++.h>
using namespace std;

int n;
double a[1005],b[1005];

double f(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double aa = y2-y1,bb = x1-x2,cc = x2*y1-x1*y2;
    return abs(aa*x3+bb*y3+cc)/sqrt(aa*aa+bb*bb);
}
int main()
{
    ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++)   cin >> a[i] >> b[i];
	double ans = 1e18;
	for(int i = 1;i <= n;i++)
    {
        int j = i+1,k = j+1;
        if(j > n)   j -= n;
        if(k > n)   k -= n;
        ans = min(ans,f(a[i],b[i],a[j],b[j],a[k],b[k]));
        ans = min(ans,f(a[i],b[i],a[k],b[k],a[j],b[j]));
        ans = min(ans,f(a[j],b[j],a[k],b[k],a[i],b[i]));
    }
    cout << fixed << setprecision(8) << ans/2 << endl;
	return 0;
}
