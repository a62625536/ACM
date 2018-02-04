#include<bits/stdc++.h>
using namespace std;

int n,m,pre[1500005],deg[1500005] = {0},sum[1500005] = {0};

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
    for(int i = 1;i <= n;i++)   pre[i] = i;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        join(x,y);
        deg[x]++;
        deg[y]++;
    }
    for(int i = 1;i <= n;i++)   sum[findd(i)]++;
    for(int i = 1;i <= n;i++)
    {
        if(deg[i] != sum[findd(i)]-1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
