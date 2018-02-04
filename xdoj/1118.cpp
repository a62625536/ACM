#include<bits/stdc++.h>
#define PI (atan(1)*4)
using namespace std;

int a[6],b[6],vis[6] = {0};
double ans;

void dfs(int cnt)
{
    if(cnt == 6)
    {
        if(b[0]+b[1]+b[3] == b[0]+b[2]+b[4] && b[0]+b[2]+b[4] == b[1]+b[2]+b[5])
        {
            ans = sqrt(3)/4*((b[0]+b[2]+b[4])*(b[0]+b[2]+b[4])-b[0]*b[0]-b[1]*b[1]-b[2]*b[2]);
        }
    }
    for(int i = 0;i < 6;i++)
    {
        if(vis[i])  continue;
        b[cnt] = a[i];
        vis[i] = 1;
        dfs(cnt+1);
        vis[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5])
    {
        ans = 0;
        dfs(0);
        if(ans > 1e-5) cout << fixed << setprecision(2) << ans << endl;
        else    cout << 0 << endl;
    }
    return 0;
}
