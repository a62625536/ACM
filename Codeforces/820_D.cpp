
#include<bits/stdc++.h>
using namespace std;

int n,a[1000005],cnt[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    long long sum = 0,cntl = 0,cntr = 0;
    for(int i = 1;i <= n;i++)
    {
        sum += abs(a[i]-i);
        if(a[i] >= i)
        {
            cntl++;
            cnt[a[i]-i]++;
        }
        else    cntr++;
    }
    long long ans = sum;
    int num = 0;
    for(int i = 1;i < n;i++)
    {
        cntl -= cnt[i-1];
        cntr += cnt[i-1];
        sum = sum-cntl+cntr-abs(a[n-i+1]-n-1)+abs(a[n-i+1]-1);
        if(a[n-i+1]+i-1 < n)    cnt[a[n-i+1]+i-1]++;
        cntl++;
        cntr--;
        if(sum < ans)
        {
            ans = sum;
            num = i;
        }
    }
    cout << ans << " " << num << endl;
    return 0;
}
