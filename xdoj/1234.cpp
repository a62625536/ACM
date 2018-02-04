#include<bits/stdc++.h>
using namespace std;

int n;
double a[25],b[25],R;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    if(n == 0)
    {
        cout << "0.00" << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)   cin >> a[i];
    cin >> R;
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    int l = 1,r = n,cnt = 1;
    while(l <= r)
    {
        if(cnt%2)   b[r--] = a[cnt++];
        else    b[l++] = a[cnt++];
    }
    double ans = b[1]+b[n];
    for(int i = 1;i < n;i++)    ans += 2*sqrt(R*(b[i]+b[i+1]-R));
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
