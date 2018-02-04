#include<bits/stdc++.h>
using namespace std;

int n,m,a[105][105],cnt1[105] = {0},cnt2[105] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    int flag = 1;
    if(n > m)   flag = 0;
    if(flag)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)   cin >> a[i][j];
        }
    }
    else
    {
        swap(n,m);
        for(int j = 1;j <= m;j++)
        {
            for(int i = 1;i <= n;i++)   cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        int minn = 1000;
        for(int j = 1;j <= m;j++)   minn = min(minn,a[i][j]);
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] != minn)
            {
                int t = a[i][j]-minn;
                cnt2[j] += t;
                for(int k = 1;k <= n;k++)   a[k][j] -= t;
            }
            a[i][j] -= minn;
        }
        cnt1[i] += minn;
    }
    int ok = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] != 0)    ok = 0;
        }
    }
    if(!ok)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)   ans += cnt1[i];
    for(int i = 1;i <= m;i++)   ans += cnt2[i];
    cout << ans << endl;
    if(flag)
    {
        for(int i = 1;i <= n;i++)
        {
            while(cnt1[i])
            {
                cnt1[i]--;
                cout << "row " << i << endl;
            }
        }
        for(int i = 1;i <= m;i++)
        {
            while(cnt2[i])
            {
                cnt2[i]--;
                cout << "col " << i << endl;
            }
        }
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            while(cnt1[i])
            {
                cnt1[i]--;
                cout << "col " << i << endl;
            }
        }
        for(int i = 1;i <= m;i++)
        {
            while(cnt2[i])
            {
                cnt2[i]--;
                cout << "row " << i << endl;
            }
        }
    }
    return 0;
}
