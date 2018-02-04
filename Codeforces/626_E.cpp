#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200005],sum[200005] = {0};

bool ok(int x,int xx)
{
    long long t1 = (sum[n]-sum[n-x]+sum[xx]-sum[xx-x-1])*(2*x+3);
    long long t2 = (sum[n]-sum[n-x-1]+sum[xx]-sum[xx-x-2])*(2*x+1);
    return t2 > t1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++)   sum[i] = sum[i-1]+a[i];
    int ansmid,anslen;
    double ans = -1;
    for(int i = 1;i <= n;i++)
    {
        int l = 0,r = min(i-1,n-i);
        while(l < r)
        {
            int mid = (l+r)/2;
            if(ok(mid,i))   l = mid+1;
            else    r = mid;
        }
        double t = 1.0*(sum[n]-sum[n-l]+sum[i]-sum[i-l-1])/(2*l+1)-a[i];
        if(t > ans)
        {
            ans = t;
            ansmid = i;
            anslen = l;
        }
    }
    cout << anslen*2+1 << endl;
    cout << a[ansmid];
    for(int i = 1,j = ansmid-1,k = n;i <= anslen;i++,j--,k--)   cout << " " << a[j] << " " << a[k];
    cout << endl;
    return 0;
}
