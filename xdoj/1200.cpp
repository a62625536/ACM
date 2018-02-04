#include <bits/stdc++.h>
using namespace std;

long long n;

long long qpower(long long a,long long b,long long c)
{
    a %= c;
    long long ans = 1;
    while(b)
    {
        if(b%2) ans = ans*a%c;
        a = a*a%c;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n) cout << ((qpower(2,n,2097151)-1)*2+2097151)%2097151 << endl;
	return 0;
}
