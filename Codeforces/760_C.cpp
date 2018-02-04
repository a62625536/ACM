#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[200005],vis[200005] = {0};

void dfs(int x)
{
    vis[x] = 1;
    if(!vis[a[x]])  dfs(a[x]);
}

int main()
{
    cin >> n;
    int cnt1 = 0;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])  continue;
        dfs(i);
        cnt1++;
    }
    int cnt2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(x)   cnt2++;
    }
    if(cnt1 == 1)   cnt1 = 0;
    if(cnt2%2 == 0)  cnt1++;
    cout << cnt1 << endl;
    return 0;
}
