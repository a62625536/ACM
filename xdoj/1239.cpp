#include<bits/stdc++.h>
using namespace std;

int n,k,a[100005][35],ok[100005][35];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i = 1;i <= n;i++)
        {
            int x;
            scanf("%d",&x);
            for(int j = 1;j <= 30;j++)
            {
                a[i][j] = x%2;
                x /= 2;
            }
        }
        for(int i = 1;i <= n;i++)   ok[i][31] = 1;
        int ans = 0;
        for(int j = 30;j >= 1;j--)
        {
            int cnt = 0,now = 0;
            for(int i = 1;i <= n;i++)
            {
                now ^= a[i][j];
                if(now == 0 && ok[i][j+1])
                {
                    ok[i][j] = 1;
                    cnt++;
                }
                else    ok[i][j] = 0;
            }
            if(cnt < k || now == 1)
            {
                ans += (1<<(j-1));
                for(int i = 1;i <= n;i++)   ok[i][j] = ok[i][j+1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
