#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
long long qpower(long long a, long long b, long long c)
{
    long long ans = 1;
    a = a%c;
    while(b)
    {
        if(b%2)    ans = ans*a%c;
        a = a*a%c;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    cout << (qpower(3,n+1,MOD)-1)*qpower(2,MOD-2,MOD)%MOD << endl;

    return 0;
}
