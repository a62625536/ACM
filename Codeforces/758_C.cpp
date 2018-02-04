#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,x,y;
long long k,a[105][105];

int main()
{
    cin >> n >> m >> k >> x >> y;
    int t = n*m;
    if(n > 2)   t += (n-2)*m;
    for(int i = 2;i < n;i++)
    {
        for(int j = 1;j <= m;j++)   a[i][j] = k/t*2;
    }
    for(int i = 1;i <= m;i++)
    {
        a[1][i] = k/t;
        a[n][i] = k/t;
    }
    int tt = k%t;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(tt > 0)
            {
                a[i][j]++;
                tt--;
            }
        }
    }
    for(int i = n-1;i > 1;i--)
    {
        for(int j = 1;j <= m;j++)
        {
            if(tt > 0)
            {
                a[i][j]++;
                tt--;
            }
        }
    }
    long long maxx = 0,minn = 1e18;
    for(int i =1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            maxx = max(maxx,a[i][j]);
            minn = min(minn,a[i][j]);
        }
    }
    cout << maxx << " " << minn << " " << a[x][y] << endl;
    return 0;
}
