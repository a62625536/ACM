#include<bits/stdc++.h>
using namespace std;

int n,a;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> a;
    double t = 180.0/n;
    int ans;
    double minn = 360;
    for(int i = 1;i <= n-2;i++)
    {
        if(abs(i*t-a) < minn)
        {
            ans = i+2;
            minn = abs(i*t-a);
        }
    }
    cout << "2 1 " << ans << endl;
    return 0;
}
