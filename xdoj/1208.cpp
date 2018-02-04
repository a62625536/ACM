#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;

int a,b,k;

LL qmod(LL a, LL b, LL c)
{
    LL ans = 1;
    a = a%c;
    while(b)
    {
        if(b&1)    ans = ans*a%c;
        b >>= 1;
        a = a*a%c;
    }
    return ans;
}

int main()
{
	ios::sync_with_stdio(false);
    while(cin >> a >> b >> k)
    {
        LL x = qmod(a,b,k-1);
        if(x == 0)  x = k-1;
        cout << (qmod(a,b,MOD)-x+MOD)%MOD*qmod(k-1,MOD-2,MOD)%MOD << endl;
    }
    return 0;
}
