#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

char a[100005];
int vis[100005];

int main()
{
    ios::sync_with_stdio(0);
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        gets(a+1);
        int n = strlen(a+1);
        n++;
        a[n] = ' ';
        memset(vis,0,sizeof(vis));
        int flag = 0;
        for(int i = n/2;i >= 2;i--)
        {
            if(vis[i])  continue;
            if(n%i) continue;
            int ok = 1;
            for(int j = i;j <= n;j += i)
            {
                if(a[j] != ' ') ok = 0;
            }
            if(ok == 0)
            {
                for(int t = 2;t*t <= i;t++)
                {
                    if(i%t == 0)
                    {
                        vis[t] = 1;
                        vis[i/t] = 1;
                    }
                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag)    printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}
