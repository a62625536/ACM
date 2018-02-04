#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n,m,s,d,a[505][505],v[505],vis[505],dis[505],sum[505],pre[505],cnt[505];

void printff(int x)
{
    if(pre[x] != s) printff(pre[x]);
    cout << " " << x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> d;
    memset(a,0x3f,sizeof(a));
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    for(int i = 0;i < n;i++)
    {
        cin >> v[i];
        sum[i] = v[i];
        cnt[i] = 1;
    }
    while(m--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x][y] = a[y][x] = min(a[y][x],z);
    }
    dis[s] = 0;
    for(int i = 1;i <= n;i++)
    {
        int k = -1,minn = INF;
        for(int j = 0;j < n;j++)
        {
            if(!vis[j] && dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        if(k == -1) break;
        vis[k] = 1;
        for(int j = 0;j < n;j++)
        {
            if(vis[j])  continue;
            if(dis[k]+a[k][j] < dis[j])
            {
                cnt[j] = cnt[k];
                dis[j] = dis[k]+a[k][j];
                sum[j] = sum[k]+v[j];
                pre[j] = k;
            }
            else if(dis[k]+a[k][j] == dis[j])
            {
                cnt[j] += cnt[k];
                if(sum[k]+v[j] > sum[j])
                {
                    sum[j] = sum[k]+v[j];
                    pre[j] = k;
                }
            }
        }
    }
    cout << cnt[d] << " " << sum[d] << endl;
    cout << s;
    printff(d);
    cout << endl;
    return 0;
}
