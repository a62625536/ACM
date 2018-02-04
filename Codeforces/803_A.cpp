#include<bits/stdc++.h>
using namespace std;

int n,k,a[105][105] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(k > n*n)
    {
        cout << - 1 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(a[i][j])   continue;
            if(k >= 1 && i == j)
            {
                k--;
                a[i][j] = 1;
            }
            else if(k >= 2)
            {
                k -= 2;
                a[i][j] = 1;
                a[j][i] = 1;
            }
        }
    }
    if(k != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
