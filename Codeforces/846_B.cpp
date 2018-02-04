#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[50];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> m;
    int sum = 0;
    for(int i = 1;i <= k;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a+1,a+1+k);
    int ans = 0;
    for(int i = 0;i <= n;i++)
    {
        int cnt = n-i,left = m-sum*i,now = (k+1)*i;
        if(left < 0)    break;
        for(int j = 1;j <= k;j++)
        {
            if(left < a[j]*cnt)
            {
                now += min(cnt,left/a[j]);
                break;
            }
            now += cnt;
            left -= a[j]*cnt;
        }
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}
