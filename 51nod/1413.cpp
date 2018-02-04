#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int ans = 0;
    while(n)
    {
        ans = max(ans,n%10);
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}
