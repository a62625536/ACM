#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0,now = 1;
    for(int i = 1;i <= n;i++)
    {
        now *= i;
        ans += now;
    }
    cout << ans << endl;
    return 0;
}
