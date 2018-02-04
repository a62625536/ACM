
#include<bits/stdc++.h>
using namespace std;

int n,a[300005],lmax[300005],lmin[300005],rmax[300005],rmin[300005],cnt[600005] = {0};

long long f(int l,int r)
{
    if(l == r)  return 1;
    int mid = (l+r)/2;
    long long ans = f(l,mid)+f(mid+1,r);
    lmax[mid] = a[mid];
    lmin[mid] = a[mid];
    for(int i = mid-1;i >= l;i--)
    {
        lmax[i] = max(a[i],lmax[i+1]);
        lmin[i] = min(a[i],lmin[i+1]);
    }
    rmax[mid+1] = a[mid+1];
    rmin[mid+1] = a[mid+1];
    for(int i = mid+2;i <= r;i++)
    {
        rmax[i] = max(a[i],rmax[i-1]);
        rmin[i] = min(a[i],rmin[i-1]);
    }
    for(int i = l;i <= mid;i++)
    {
        int t = lmax[i]-lmin[i]+i;
        if(mid < t && t <= r && rmax[t] <= lmax[i] && rmin[t] >= lmin[i])   ans++;
    }
    for(int i = mid+1;i <= r;i++)
    {
        int t = i-(rmax[i]-rmin[i]);
        if(l <= t && t <= mid && lmax[t] <= rmax[i] && lmin[t] >= rmin[i])  ans++;
    }
    int j = mid+1,k = mid+1;
    for(int i = mid;i >= l;i--)
    {
        while(j <= r && rmax[j] < lmax[i])
        {
            cnt[rmax[j]-j+300000]--;
            j++;
        }
        while(k <= r && rmin[k] > lmin[i])
        {
            cnt[rmax[k]-k+300000]++;
            k++;
        }
        if(j <= k)  ans += cnt[lmin[i]-i+300000];
    }
    for(int i = mid+1;i <= r;i++)   cnt[rmax[i]-i+300000] = 0;
    j = mid;
    k = mid;
    for(int i = mid+1;i <= r;i++)
    {
        while(j >= l && lmax[j] < rmax[i])
        {
            cnt[lmax[j]+j]--;
            j--;
        }
        while(k >= l && lmin[k] > rmin[i])
        {
            cnt[lmax[k]+k]++;
            k--;
        }
        if(k <= j)  ans += cnt[rmin[i]+i];
    }
    for(int i = mid;i >= l;i--) cnt[lmax[i]+i] = 0;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x] = y;
    }
    cout << f(1,n) << endl;
    return 0;
}
