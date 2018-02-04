#include<bits/stdc++.h>
using namespace std;

int n,k,a[105],vis[105] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1;i <= k;i++)   cin >> a[i];
    int now = 1,num = n;
    for(int i = 1;i <= k;i++)
    {
        a[i] %= num--;
        while(a[i])
        {
            now++;
            if(now > n) now = 1;
            while(vis[now])
            {
                now++;
                if(now > n) now = 1;
            }
            a[i]--;
        }
        vis[now] = 1;
        cout << now << " ";
        while(vis[now])
        {
            now++;
            if(now > n) now = 1;
        }
    }
    return 0;
}
