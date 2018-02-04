#include<bits/stdc++.h>
using namespace std;

int n,m;
long long k;
long long a[100005],b[100005];

bool ok(long long x)
{
    long long cnt = 0;
    for(int i = 1;i <= m;i++)
    {
        cnt += (lower_bound(a+1,a+1+n,x*b[i])-a-1);
        if(cnt > k) return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        k = n*m-k;
        for(int i = 1;i <= n;i++)   cin >> a[i];
        for(int i = 1;i <= n;i++)   a[i] *= 1000;
        for(int i = 1;i <= m;i++)   cin >> b[i];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        long long r = a[n]/b[1],l = a[1]/b[m];
        while(l < r)
        {
            int mid = (l+r+1)/2;
            if(ok(mid)) r = mid-1;
            else    l = mid;
        }
        cout << fixed << setprecision(2) << (double)l/1000 << endl;
    }
    return 0;
}
