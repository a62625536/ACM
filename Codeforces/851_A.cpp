#include<bits/stdc++.h>
using namespace std;

int n,k,t;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> t;
    if(t <= k)  cout << t << endl;
    else if(t <= n) cout << k << endl;
    else    cout << k-(t-n) << endl;
}



