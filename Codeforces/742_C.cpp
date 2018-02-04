#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[105],vis[105] = {0};

long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    long long ans = 1;
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])  continue;
        int now = a[i],t = 1;
        while(now != i)
        {
            t++;
            if(vis[now])
            {
                printf("-1\n");
                return 0;
            }
            vis[now] = 1;
            now = a[now];
        }
        vis[now] = 1;
        if(t%2 == 0)    t /= 2;
        ans = ans*t/gcd(ans,t);
    }
    cout << ans << endl;
    return 0;
}
