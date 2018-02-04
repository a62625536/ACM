#include<bits/stdc++.h>
using namespace std;

long long a,b;

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> a >> b;
        long long x = a+3*b,y = 4*a+4*b;
        long long t = __gcd(x,y);
        cout << x/t << "/" << y/t << endl;
    }
    return 0;
}
