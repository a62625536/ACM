#include<bits/stdc++.h>
using namespace std;

long long l,r,x,y,k;

int main()
{
    ios::sync_with_stdio(0);
    cin >> l >> r >> x >> y >> k;
    for(int i = x;i <= y;i++)
    {
        if(l <= i*k && i*k <= r)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
