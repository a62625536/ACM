#include<bits/stdc++.h>
using namespace std;

long long a,b,c,d;

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> a >> b >> c >> d;
        if(__gcd(a,b) == __gcd(c,d))    cout << "Yes" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}
