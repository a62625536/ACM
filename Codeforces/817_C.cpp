#include<bits/stdc++.h>
using namespace std;

long long n,s;

bool ok(long long x)
{
    long long t = x;
    while(t)
    {
        x -= t%10;
        t /= 10;
    }
    if(x >= s)  return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> s;
    long long l = 1,r = n+1;
    while(l < r)
    {
        long long mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else    l = mid+1;
    }
    cout << n-l+1 << endl;
    return 0;
}
