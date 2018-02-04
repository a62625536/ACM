#include<bits/stdc++.h>
using namespace std;

int n,s;
long long a[100005],b[100005];

bool ok(int x)
{
    for(int i = 1;i <= n;i++)   b[i] = a[i]+(long long)x*i;
    sort(b+1,b+1+n);
    long long sum = 0;
    for(int i = 1;i <= x;i++)   sum += b[i];
    return sum <= s;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> s;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int l = 0,r = n;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(ok(mid)) l = mid;
        else    r = mid-1;
    }
    for(int i = 1;i <= n;i++)   b[i] = a[i]+(long long)l*i;
    sort(b+1,b+1+n);
    long long sum = 0;
    for(int i = 1;i <= l;i++)   sum += b[i];
    cout << l << " " << sum << endl;
    return 0;
}
