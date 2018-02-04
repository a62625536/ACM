#include<bits/stdc++.h>
using namespace std;

int n,q,c,ans[105][105][15] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q >> c;
    for(int i = 1;i <= n;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        for(int j = 0;j <= c;j++)   ans[x][y][j] += (j+z)%(c+1);
    }
    for(int k = 0;k <= c;k++)
    {
        for(int i = 1;i <= 100;i++)
        {
            for(int j = 1;j <= 100;j++) ans[i][j][k] += ans[i][j-1][k]+ans[i-1][j][k]-ans[i-1][j-1][k];
        }
    }
    while(q--)
    {
        int t,x1,x2,y1,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= (c+1);
        cout << ans[x2][y2][t]-ans[x1-1][y2][t]-ans[x2][y1-1][t]+ans[x1-1][y1-1][t] << endl;
    }
    return 0;
}
