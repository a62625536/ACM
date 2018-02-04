#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int k,a,b;

int main()
{
    cin >> k >> a >> b;
    if(a < k && b < k || a%k && b < k || a < k && b%k)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = a/k;
    ans += b/k;
    cout << ans << endl;
    return 0;
}
