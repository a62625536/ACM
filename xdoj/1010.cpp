#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f
using namespace std;

int maxdp[100005][20],mindp[100005][20],lmax[100005],rmax[100005],a[100005],n;

void rmq_init(int len)
{
    for(int i = 1;i <= len;i++)
    {
        maxdp[i][0] = a[i];
        mindp[i][0] = a[i];
    }
    for(int j = 1;(1<<j) <= len;j++)
    {
        for(int i = 1;i+(1<<j)-1 <= len;i++)
        {
            maxdp[i][j] = max(maxdp[i][j-1],maxdp[i+(1<<(j-1))][j-1]);
            mindp[i][j] = min(mindp[i][j-1],mindp[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq_max(int l,int r)
{
    int k = (int)(log((double)(r-l+1))/log(2.0));
    return max(maxdp[l][k],maxdp[r-(1<<k)+1][k]);
}

int rmq_min(int l,int r)
{
    int k = (int)(log((double)(r-l+1))/log(2.0));
    return min(mindp[l][k],mindp[r-(1<<k)+1][k]);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
        rmq_init(n);
        int tempmax = -INF,minnum = a[1],minpos = 1;
        for(int i = 1;i < n;i++)
        {
            if(a[i] < minnum)
            {
                minnum = a[i];
                minpos = i;
            }
            int temp = rmq_max(minpos+1,i+1)-minnum;
            tempmax = max(temp,tempmax);
            lmax[i+1] = tempmax;
        }
        tempmax = -INF;
        int maxnum = a[n],maxpos = n;
        for(int i = n;i > 1;i--)
        {
            if(a[i] > maxnum)
            {
                maxnum = a[i];
                maxpos = i;
            }
            int temp = maxnum-rmq_min(i-1,maxpos-1);
            tempmax = max(temp,tempmax);
            rmax[i-1] = tempmax;
        }
        int ans = -INF;
        for(int i = 2;i < n-2;i++)  ans = max(lmax[i]+rmax[i+1],ans);
        printf("%d\n",ans);
    }
    return 0;
}
