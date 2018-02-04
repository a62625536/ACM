#include<bits/stdc++.h>
using namespace std;

long long n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if(m >= n)
    {
        cout << n << endl;
        return 0;
    }
    long long ans = ceil((-3+sqrt(9+(n-1-m)*8))/2);
    while((1+ans)*ans/2+ans+m+1 < n)    ans++;
    cout << ans+m+1 << endl;
    return 0;
}
