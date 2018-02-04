#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

int n,limit[30],dp1[1005],dp2[1005],maxx = 0;
char s[1005];

int main()
{
    scanf("%d%s",&n,s+1);
    for(int i = 0;i <= 25;i++)  scanf("%d",&limit[i]);
    memset(dp2,0x3f,sizeof(dp2));
    dp1[0] = 1;
    dp2[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j >= 1;j--)
        {
            int flag = 0,len = i-j+1;
            for(int k = j;k <= i;k++)
            {
                if(limit[s[k]-'a'] < len)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)    continue;
            dp1[i] = (dp1[i]+dp1[j-1])%MOD;
            dp2[i] = min(dp2[i],dp2[j-1]+1);
            maxx = max(maxx,i-j+1);
        }
    }
    printf("%d\n%d\n%d\n",dp1[n],maxx,dp2[n]);
    return 0;
}
