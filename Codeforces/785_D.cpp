#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;

string s;
LL l[200005] = {0},r[200005] = {0},fac[400005];

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

LL c(LL n,LL m)
{
    return fac[n]*qmod(fac[m]*fac[n-m],MOD-2,MOD)%MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    fac[0] = 1;
    for(int i = 1;i <= 400000;i++)  fac[i] = fac[i-1]*i%MOD;
    cin >> s;
    s = " "+s;
    for(int i = 1;i < s.length();i++)   l[i] = l[i-1]+(s[i] == '(');
    for(int i = s.length()-1;i >= 1;i--)    r[i] = r[i+1]+(s[i] == ')');
    long long ans = 0;
    for(int i = 1;i < s.length();i++)
    {
        if(s[i] == '(') ans = (ans+c(l[i]+r[i]-1,l[i]))%MOD;
    }
    cout << ans << endl;
    return 0;
}
