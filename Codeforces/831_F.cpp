#include<bits/stdc++.h>
using namespace std;

long long n,k,a[105],b[8000000];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    int cnt = 0;
    long long sum = k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        sum += a[i];
        for(int j = 1;j*j <= a[i];j++)
        {
            b[++cnt] = j;
            b[++cnt] = (a[i]+j-1)/j;
        }
    }
    sort(b+1,b+1+cnt);
    cnt = unique(b,b+1+cnt)-b-1;
    long long ans = 0;
    for(int i = 1;i <= cnt;i++)
    {
        long long now = 0;
        for(int j = 1;j <= n;j++)   now += (a[j]+b[i]-1)/b[i];
        if(sum/now >= b[i])   ans = max(ans,sum/now);
    }
    cout << ans << endl;
    return 0;
}
