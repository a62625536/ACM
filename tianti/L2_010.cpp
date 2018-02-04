#include<bits/stdc++.h>
using namespace std;

int n,m,k,pre[105],a[105][105] = {0};

int findd(int x)
{
    return x == pre[x]?x:pre[x] = findd(pre[x]);
}

void join(int x,int y)
{
    int xx = findd(x),yy = findd(y);
    if(xx != yy)    pre[xx] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)   pre[i] = i;
    for(int i = 1;i <= m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        if(z == 1)  join(x,y);
        else
        {
            a[x][y] = 1;
            a[y][x] = 1;
        }
    }
    while(k--)
    {
        int x,y;
        cin >> x >> y;
        if(findd(x) == findd(y) && !a[x][y])    cout << "No problem" << endl;
        else if(findd(x) == findd(y) && a[x][y])    cout << "OK but..." << endl;
        else if(findd(x) != findd(y) && a[x][y])    cout << "No way" << endl;
        else    cout << "OK" << endl;
    }
    return 0;
}
