#include<bits/stdc++.h>
using namespace std;

int n,m,ans[50005],vis[50005] = {0};

struct xx
{
    int x,id;
    friend bool operator<(xx a,xx b)
    {
        return a.x < b.x;
    }
}a[50005],b[50005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].x;
        a[i].id = i;
    }
    for(int i = 1;i <= m;i++)
    {
        cin >> b[i].x;
        b[i].id = i;
    }
    vis[0] = 1;
    vis[n+1] = 1;
    int now = 1,cnt = 1;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for(int i = 1;i <= m;i++)
    {
        while(now <= n && a[now].x <= b[i].x)
        {
            if(vis[a[now].id-1] && vis[a[now].id+1])    cnt--;
            else if(!vis[a[now].id-1] && !vis[a[now].id+1]) cnt++;
            vis[a[now].id] = 1;
            now++;
        }
        ans[b[i].id] = cnt;
    }
    for(int i = 1;i <= m;i++)   cout << ans[i] << endl;
    return 0;
}
