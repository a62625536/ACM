#include<bits/stdc++.h>
using namespace std;

long long b,q,l,m;
map<long long,long long> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> b >> q >> l >> m;
    while(m--)
    {
        int x;
        cin >> x;
        mp[x] = 1;
    }
    if(abs(b) > l)  cout << 0 << endl;
    else if(b == 0)
    {
        if(!mp.count(0))    cout << "inf" << endl;
        else    cout << 0 << endl;
    }
    else if(q == 0)
    {
        if(!mp.count(0))    cout << "inf" << endl;
        else if(!mp.count(b))    cout << 1 << endl;
        else    cout << 0 << endl;
    }
    else if(q == 1)
    {
        if(!mp.count(b))    cout << "inf" << endl;
        else    cout << 0 << endl;
    }
    else if(q == -1)
    {
        if(!mp.count(b) || !mp.count(-1*b)) cout << "inf" << endl;
        else    cout << 0 << endl;
    }
    else
    {
        int ans = 0;
        while(abs(b) <= l)
        {
            if(!mp.count(b))    ans++;
            b *= q;
        }
        cout << ans << endl;
    }
    return 0;
}
