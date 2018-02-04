#include<bits/stdc++.h>
using namespace std;

int n,a[100005][10],b[100005] = {0},c[100005];

int calc(int x,int y,int z)
{
    int t = 250-x;
    if(x == -1) return 0;
    if(2*y > z) return 2*t;
    if(4*y > z) return 4*t;
    if(8*y > z) return 6*t;
    if(16*y > z)    return 8*t;
    if(32*y > z)    return 10*t;
    return 12*t;
}

bool ok(int x)
{
    int sum1 = 0,sum2 = 0;
    for(int i = 1;i <= 5;i++)   c[i] = b[i];
    for(int i = 1;i <= 5;i++)
    {
        if(a[2][i] != -1 && a[1][i] > a[2][i]) c[i] += x;
    }
    for(int i = 1;i <= 5;i++)
    {
        sum1 += calc(a[1][i],c[i],n+x);
        sum2 += calc(a[2][i],c[i],n+x);
    }
    return sum1 > sum2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 5;j++)
        {
            cin >> a[i][j];
            if(a[i][j] >= 0)    b[j]++;
        }
    }
    for(int i = 0;i <= 1000000;i++)
    {
        if(ok(i))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
