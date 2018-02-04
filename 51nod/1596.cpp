#include<bits/stdc++.h>
using namespace std;

int n,a[1100005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 0;i <= 1100000;i++)
    {
        a[i+1] += a[i]/2;
        a[i] %= 2;
    }
    int ans = 0;
    for(int i = 0;i <= 1100000;i++)   ans += a[i];
    cout << ans << endl;
    return 0;
}
