#include<bits/stdc++.h>
using namespace std;

int n,a[55][55];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   cin >> a[i][j];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(a[i][j] == 1)    continue;
            int flag = 0;
            for(int ii = 1;ii <= n;ii++)
            {
                for(int jj = 1;jj <= n;jj++)
                {
                    if(a[ii][j]+a[i][jj] == a[i][j])    flag = 1;
                }
            }
            if(!flag)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
