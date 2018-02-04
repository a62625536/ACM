#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int tree[605][805],sum1[605][805],sum2[605][805],n,m,k,t;

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int xx,int pos,int x)
{
    while(pos <= n)
    {
        tree[xx][pos] += x;
        pos += lowbit(pos);
    }
}

int getsum(int xx,int pos)
{
    int sum = 0;
    while(pos > 0)
    {
        sum += tree[xx][pos];
        pos -= lowbit(pos);
    }
    return sum;
}

int main()
{
    while(~scanf("%d%d%d",&m,&n,&k))
    {
        memset(tree,0,sizeof(0));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                scanf("%d",&t);
                update(i,j,t);
                sum1[i][j] = -t;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                int s1 = 0,s2 = 0,endd = i+k;
                for(int l = i-k;l <= endd;l++)
                {
                    if(l < 1)   continue;
                    if(l > m)   break;
                    t = k-abs(i-l);
                    s1 += getsum(l,min(j+t,m))-getsum(l,max(j-t,1)-1);
                    s2 += min(j+t,m)-max(j-t,1)+1;
                }
                sum1[i][j] += s1;
                sum2[i][j] = s2-1;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)   printf("%.0f ",(double)sum1[i][j]/sum2[i][j]+0.000001);
            printf("\n");
        }
    }
    return 0;
}
