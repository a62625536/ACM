#include<bits/stdc++.h>
using namespace std;

int n,pre[1005],a[1005][1005],has[1005] = {0},sum[1005] = {0},ans[1005],cnt = 0;
string s;

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
    for(int i = 1;i <= 1000;i++)   pre[i] = i;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i][0] >> s;
        for(int j = 1;j <= a[i][0];j++)
        {
            cin >> a[i][j];
            has[a[i][j]] = 1;
        }
        for(int j = 1;j <= a[i][0];j++)
        {
            for(int k = j+1;k <= a[i][0];k++)   join(a[i][j],a[i][k]);
        }
    }
    for(int i = 1;i <= n;i++)   sum[findd(a[i][1])]++;
    for(int i = 1;i <= 1000;i++)
    {
        if(has[i] && pre[i] == i)   ans[++cnt] = sum[i];
    }
    sort(ans+1,ans+1+cnt);
    cout << cnt << endl;
    cout << ans[cnt];
    for(int i = cnt-1;i >= 1;i--)   cout << " " << ans[i];
    cout << endl;
    return 0;
}
