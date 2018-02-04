#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],pre[400005],b[200005][3] = {0};

int findd(int x)
{
    return x == pre[x]?x:pre[x] = findd(pre[x]);
}

void join(int a,int b)
{
    int x = findd(a),y = findd(b);
    if(x != y) pre[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0;i < n;i++)    cin >> a[i];
    for(int i = 1;i <= m;i++)
    {
        int q;
        cin >> q;
        while(q--)
        {
            int x;
            cin >> x;
            x--;
            b[x][++b[x][0]] = i;
        }
    }
    int endd = 2*m;
    for(int i = 0;i < endd;i++) pre[i] = i;
    for(int i = 0;i < n;i++)
    {
        if(a[i])
        {
            join(b[i][1],b[i][2]);
            join(b[i][1]+m,b[i][2]+m);
        }
        else
        {
            join(b[i][1],b[i][2]+m);
            join(b[i][1]+m,b[i][2]);
        }
    }
    for(int i = 1;i <= m;i++)
    {
        if(findd(i) == findd(i+m))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
