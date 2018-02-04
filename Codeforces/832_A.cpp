#include<bits/stdc++.h>
using namespace std;

long long n,k;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    long long t = n/k;
    if(t%2) cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
