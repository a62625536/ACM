
#include<bits/stdc++.h>
using namespace std;

int c,v0,v1,a,l;

int main()
{
    ios::sync_with_stdio(0);
    cin >> c >> v0 >> v1 >> a >> l;
    int ans = 0,now = l,v = v0-a;
    while(1)
    {
        ans++;
        now -= l;
        v += a;
        if(v > v1)  v = v1;
        now += v;
        if(now >= c)    break;
    }
    cout << ans << endl;
    return 0;
}
