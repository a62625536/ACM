#include<bits/stdc++.h>
using namespace std;

int n,m,k,x[5005],y[5005],vis[505] = {0},pre[505];

int findd(int x)
{
    return x == pre[x]?x:pre[x] = findd(pre[x]);
}

void join(int x,int y)
{
    int xx = findd(x),yy = findd(y);
    if(xx != yy)    pre[xx] = yy;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= m;i++)   cin >> x[i] >> y[i];
    for(int i = 0;i < n;i++)    pre[i] = i;
    for(int i = 1;i <= m;i++)   join(x[i],y[i]);
    int now1 = 0,now2 = 0;
    for(int i = 0;i < n;i++)
    {
        if(pre[i] == i) now1++;
    }
    cin >> k;
    while(k--)
    {
        for(int i = 0;i < n;i++)    pre[i] = i;
        int t;
        cin >> t;
        vis[t] = 1;
        for(int i = 1;i <= m;i++)
        {
            if(!vis[x[i]] && !vis[y[i]])    join(x[i],y[i]);
        }
        for(int i = 0;i < n;i++)
        {
            if(!vis[i] && pre[i] == i)  now2++;
        }
        if(now1 == now2 || now1 == now2+1)  cout << "City " << t << " is lost." << endl;
        else    cout << "Red Alert: City " << t << " is lost!" << endl;
        now1 = now2;
        now2 = 0;
    }
    if(now1 == 0)   cout << "Game Over." << endl;
    return 0;
}
