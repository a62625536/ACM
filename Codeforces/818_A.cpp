#include<bits/stdc++.h>
using namespace std;

long long n,k;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    long long t = n/2/(k+1);
    cout << t << " " << t*k << " " << n-t*(1+k) << endl;
    return 0;
}
