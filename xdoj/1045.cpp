#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[6][6],dir[4][2] = {-1,0,0,-1,1,0,0,1};

bool dfs(int x,int y)
{
    a[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int xx = x+dir[i][0],yy = y+dir[i][1];
        if(xx > 5 || xx < 1 || yy > 5 || yy < 1 || a[xx][yy])   continue;
        if(dfs(xx,yy))
        {
            a[x][y] = 0;
            return 0;
        }
    }
    a[x][y] = 0;
    return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 1;i <= 5;i++)
        {
            for(int j = 1;j <= 5;j++)   scanf("%1d",&a[i][j]);
        }
        int flag = 0;
        for(int i = 1;i <= 5;i++)
        {
            for(int j = 1;j <= 5;j++)
            {
                if(!a[i][j] && dfs(i,j))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)    break;
        }
        if(flag)    printf("win\n");
        else    printf("lose\n");
    }
    return 0;
}
