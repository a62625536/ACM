#include<bits/stdc++.h>
using namespace std;

long long m,b;

int main()
{
    ios::sync_with_stdio(0);
    cin >> m >> b;
    long long ans = 0;
    for(int y = 0;y <= b;y++)
    {
        long long x = (b-y)*m;
        ans = max(ans,(x+1)*(y+1)*y/2+(y+1)*(x+1)*x/2);
    }
    cout << ans << endl;
    return 0;
}
