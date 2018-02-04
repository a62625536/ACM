#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    int ans = 1,t = n;
    while(n--)  ans <<= 1;
    cout << "2^" << t << " = " << ans << endl;
    return 0;
}
