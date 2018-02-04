#include<bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int a,b,c,n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> n;
    int ans = 0;
    while(n--)
    {
        int x;
        cin >> x;
        if(b < x && x < c)  ans++;
    }
    cout << ans << endl;
    return 0;
}
