#include<bits/stdc++.h>
using namespace std;

int n,vis[100005] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int now = 0,ans = 0;
    for(int i = 1;i <= 2*n;i++)
    {
        int x;
        cin >> x;
        if(vis[x])  now--;
        else
        {
            now++;
            vis[x] = 1;
            ans = max(now,ans);
        }
    }
    cout << ans << endl;
    return 0;
}
