#include<bits/stdc++.h>
using namespace std;

int n,m,pos[5][200005],ok[200005] = {0};
struct xx
{
    int p,a,b;
    friend bool operator <(xx a,xx b)
    {
        return a.p < b.p;
    }
}a[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i].p;
    for(int i = 1;i <= n;i++)   cin >> a[i].a;
    for(int i = 1;i <= n;i++)   cin >> a[i].b;
    sort(a+1,a+1+n);
    int cnt[5] = {0};
    for(int i = 1;i <= n;i++)
    {
        int x = a[i].a,y = a[i].b;
        pos[x][++cnt[x]] = i;
        if(x != y)  pos[y][++cnt[y]] = i;
    }
    cin >> m;
    int now[5] = {1,1,1,1,1};
    while(m--)
    {
        int x;
        cin >> x;
        while(ok[pos[x][now[x]]])   now[x]++;
        if(now[x] > cnt[x]) cout << -1 << " ";
        else
        {
            ok[pos[x][now[x]]] = 1;
            cout << a[pos[x][now[x]]].p << " ";
        }
    }
    return 0;
}
