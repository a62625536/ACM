#include<iostream>
#include<cstdio>
using namespace std;
long long a[505][505];
int main()
{
    int n,x,y;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
            if(!a[i][j])
            {
                x = i;
                y = j;
            }
        }
    }
    if(n == 1)
    {
        printf("1\n");
        return 0;
    }
    long long sum = 0;
    for(int i = 1;i <= n;i++)
    {
        if(i != x)
        {
            for(int j = 1;j <= n;j++)
            {
                sum += a[i][j];
            }
            break;
        }
    }
    long long now = 0;
    for(int i = 1;i <= n;i++)
    {
        now += a[x][i];
    }
    a[x][y] = sum-now;
    for(int i = 1;i <= n;i++)
    {
        long long temp1 = 0,temp2 = 0;
        for(int j = 1;j <= n;j++)
        {
            temp1 += a[i][j];
            temp2 += a[j][i];
        }
        if(temp1 != sum || temp2 != sum)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    long long temp1 = 0,temp2 = 0;
    for(int i = 1;i <=n;i++)
    {
        temp1 += a[i][i];
        temp2 += a[i][n-i+1];
    }
    if(temp1 != sum || temp2 != sum)
    {
        cout << -1 << endl;
        return 0;
    }
    if(a[x][y] <= 0)    cout << -1 << endl;
    else                cout << a[x][y] << endl;
    return 0;
}
