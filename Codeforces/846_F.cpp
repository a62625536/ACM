#include<bits/stdc++.h>
using namespace std;

int n,a[1000005],la[1000005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        long long t1 = i-la[a[i]],t2 = n-i+1;
        ans += t1*t2;
        la[a[i]] = i;
    }
    ans *= 2;
    ans -= n;
    cout << fixed << setprecision(10) << 1.0*ans/n/n << endl;
    return 0;
}
