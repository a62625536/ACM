#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[10][10],ans[10][10];

int fmove()
{
    int flag = 0;
    for(int j = 0;j < 7;j++)
    {
        for(int i = 0;i < 5;i++)
        {
            if(a[i][j])
            {
                int t = j;
                for(;t > 0 && a[i][t-1] == 0;t--);
                if(t != j)  flag = 1;
                swap(a[i][j],a[i][t]);
            }
        }
    }
    return flag;
}

void fdel()
{
    memset(ans,0,sizeof(ans));
    for(int i = 0;i < 5;i++)
    {
        int l = 0,r = 1,last = a[i][0];
        while(r < 7)
        {
            if(a[i][r] != last)
            {
                if(r-l >= 3)
                {
                    for(int k = l;k < r;k++)    ans[i][k] = 1;
                }
                l = r;
                last = a[i][r];
            }
            r++;
        }
        if(r-l >= 3)
        {
            for(int k = l;k < r;k++)    ans[i][k] = 1;
        }
    }
    for(int j = 0;j < 7;j++)
    {
        int l = 0,r = 1,last = a[0][j];
        while(r < 5)
        {
            if(a[r][j] != last)
            {
                if(r-l >= 3)
                {
                    for(int k = l;k < r;k++)    ans[k][j] = 1;
                }
                l = r;
                last = a[r][j];
            }
            r++;
        }
        if(r-l >= 3)
        {
            for(int k = 1;k < r;k++)    ans[k][j] = 1;
        }
    }
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            if(ans[i][j])   a[i][j] = 0;
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        int flag = 0;
        memset(a,0,sizeof(a));
        for(int i = 0;i < 5;i++)
        {
            for(int j = 0;j < 7;j++)
            {
                scanf("%d",&a[i][j]);
                if(!a[i][j])    break;
            }
        }
        while(n--)
        {
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            if(!a[x][y] || d+x > 4 || d+x < 0)
            {
                printf("Runtime Error\n");
                flag = 1;
            }
            else
            {
                swap(a[x][y],a[x+d][y]);
                fmove();
                fdel();
                while(fmove())  fdel();
            }
        }
        if(flag)    continue;
        for(int i = 0;i < 5;i++)
        {
            for(int j = 0;j < 7;j++)
            {
                if(a[i][j])    flag = 1;
            }
        }
        if(!flag)    printf("Accepted\n");
        else    printf("Wrong Answer\n");
    }
    return 0;
}
