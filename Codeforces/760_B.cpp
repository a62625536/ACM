#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,k;

bool ok(long long x)
{
    long long t = -x;
    if(x <= k)  t += (1+x)*x/2+k-x;
    else    t += (x+x-k+1)*k/2;
    k = n-k+1;
    if(x <= k)  t += (1+x)*x/2+k-x;
    else    t += (x+x-k+1)*k/2;
    k = n-k+1;
    if(t > m)   return 0;
    return 1;
}

int main()
{
    cin >> n >> m >> k;
    int l = 1,r = m;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(ok(mid)) l = mid;
        else    r = mid-1;
    }
    cout << l << endl;
    return 0;
}
