#include<bits/stdc++.h>
using namespace std;

int r,d,n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> r >> d >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        double x,y,rr;
        cin >> x >> y >> rr;
        double dis = sqrt(x*x+y*y);
        if(dis-rr > r-d-1e-9 && dis+rr < r+1e-9)    ans++;
    }
    cout << ans << endl;
    return 0;
}
