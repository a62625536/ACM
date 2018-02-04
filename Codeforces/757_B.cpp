#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,vis[100005] = {0},cnt[100005] = {0};

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 1;
    for(int i = 2;i <= 1e5;i++)
    {
        if(vis[i])  continue;
        int t = 0;
        for(int j = i;j <= 1e5;j += i)
        {
            vis[j] = 1;
            t += cnt[j];
        }
        ans = max(ans,t);
    }
    cout << ans << endl;
    return 0;
}
