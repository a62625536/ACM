#include<bits/stdc++.h>
using namespace std;

int n,l[5005],r[5005];
long long a[5005],sum[5005] = {0},lm[5005],rm[5005];

long long f(int l,int r)
{
    long long t1 = r == 0?0:sum[r-1];
    long long t2 = l == 0?0:sum[l-1];
    return t1-t2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    }
    for(int i = 0;i <= n;i++)
    {
        int t;
        long long maxx = -1e18;
        for(int j = 0;j <= i;j++)
        {
            if(f(0,j)-f(j,i) > maxx)
            {
                maxx = f(0,j)-f(j,i);
                t = j;
            }
        }
        l[i] = t;
        lm[i] = maxx;
        maxx = -1e18;
        for(int j = i;j <= n;j++)
        {
            if(f(i,j)-f(j,n) > maxx)
            {
                maxx = f(i,j)-f(j,n);
                t = j;
            }
        }
        r[i] = t;
        rm[i] = maxx;
    }
    long long maxx = -1e18;
    int ans1,ans2,ans3;
    for(int i = 0;i <= n;i++)
    {
        if(lm[i]+rm[i] > maxx)
        {
            maxx = lm[i]+rm[i];
            ans1 = l[i];
            ans2 = i;
            ans3 = r[i];
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}
