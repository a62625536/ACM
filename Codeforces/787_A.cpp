#include<bits/stdc++.h>
using namespace std;

int a,b,c,d;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    int t = gcd(a,c);
    if(abs(b-d)%t)
    {
        cout << -1 << endl;
        return 0;
    }
    while(b != d)
    {
        if(b < d)   b += a;
        else    d += c;
    }
    cout << b << endl;
    return 0;
}
