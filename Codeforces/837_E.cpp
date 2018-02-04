#include<bits/stdc++.h>
using namespace std;

long long a,b;

int main()
{
    ios::sync_with_stdio(0);
    cin >> a >> b;
    long long t = __gcd(a,b);
    a /= t;
    b /= t;
    vector<long long> v;
    for(long long i = 2;i*i <= a;i++)
    {
        while(a%i == 0)
        {
            a /= i;
            v.push_back(i);
        }
    }
    if(a > 1)   v.push_back(a);
    long long ans = 0;
    while(b)
    {
        long long t = b;
        for(auto it = v.begin();it != v.end();it++) t = min(t,b%(*it));
        ans += t;
        b -= t;
        vector<long long> vv;
        for(auto it = v.begin();it != v.end();it++)
        {
            long long t = *it;
            if(b%t == 0)    b /= t;
            else    vv.push_back(t);
        }
        v = vv;
    }
    cout << ans << endl;
    return 0;
}
