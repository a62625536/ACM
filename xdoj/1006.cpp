#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int bin[100005][35],two[35],n;
double a[100005],b[100005],c[100005];

int main()
{
    two[0] = 1;
    for(int i = 1;i <= 30;i++)  two[i] = two[i-1]*2;
    while(~scanf("%d",&n))
    {
        memset(bin,0,sizeof(bin));
        int maxcnt = 0;
        double ans1 = 0,ans2 = 0,ans3 = 0;
        for(int i = 1;i <= n;i++)
        {
            int x;
            scanf("%d",&x);
            ans1 -= x;
            ans2 -= x;
            ans3 -= x;
            int cnt = 0;
            while(x)
            {
                bin[i][++cnt] = x%2;
                x /= 2;
            }
            maxcnt = max(cnt,maxcnt);
        }
        for(int j = 1;j <= maxcnt;j++)
        {
            int last0 = 0,last1 = 0;
            for(int i = 1;i <= n;i++)
            {
                if(bin[i][j] == 1)
                {
                    if(last1 > 0)   a[i] = a[last1-1]+i-last1;
                    else            a[i] = i;
                    b[i] = i-last0;
                    c[i] = i;
                    last1 = i;
                }
                else
                {
                    if(i > 1)   a[i] = a[i-1];
                    else        a[i] = 0;
                    b[i] = 0;
                    c[i] = last1;
                    last0 = i;
                }
                ans1 += a[i]*two[j];
                ans2 += b[i]*two[j];
                ans3 += c[i]*two[j];
            }
        }
        printf("%.3lf %.3lf %.3lf\n",ans1/n/n,ans2/n/n,ans3/n/n);
    }
    return 0;
}
