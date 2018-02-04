#include<bits/stdc++.h>
using namespace std;

long long x,y,xx,yy;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> x >> y >> xx >> yy;
        if(x*yy == y*xx)
        {
            cout << 0 << endl;
            continue;
        }
        if(x != 0 && xx == 0 || xx >= yy)
        {
            cout << -1 << endl;
            continue;
        }
        if(x*yy < xx*y)
        {
            long long t = y-x;
            long long ans = t/(yy-xx);
            if(ans*yy-t < ans*xx)   ans++;
            cout << ans*yy-y << endl;
        }
        else
        {
            long long ans = x/xx;
            if(ans*xx < x)  ans++;
            cout << ans*yy-y << endl;
        }
    }
    return 0;
}
