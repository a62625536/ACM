#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int n,x[1005],y[1005],r[1005],cnt[1005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> x[i] >> y[i] >> r[i];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(i == j)  continue;
            if(sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j])) <= r[j]-r[i])  cnt[i]++;
        }
    }
    double ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(cnt[i] == 0 || cnt[i]%2) ans += PI*r[i]*r[i];
        else    ans -= PI*r[i]*r[i];
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
