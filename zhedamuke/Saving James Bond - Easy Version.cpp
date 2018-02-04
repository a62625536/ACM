#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

struct pos
{
    int x,y;
}a[105],temp;
int n,d,visit[105];
queue<struct pos> q;

int canreach(int x,int y,int xx,int yy,int add)
{
    if((x-xx)*(x-xx)+(y-yy)*(y-yy) <= (d+add)*(d+add))  return 1;
    return 0;
}

int safe(int x,int y)
{
    if(50-x <= d || x+50 <= d || 50-y <= d || y+50 <= d)    return 1;
    return 0;
}

int main()
{
    scanf("%d%d",&n,&d);
    if(d > 42)
    {
        printf("Yes\n");
        return 0;
    }
    for(int i = 1;i <= n;i++)   scanf("%d%d",&a[i].x,&a[i].y);
    for(int i = 1;i <= n;i++)
    {
        if(!canreach(0,0,a[i].x,a[i].y,15) || visit[i])    continue;
        q.push(a[i]);
        visit[i] = 1;
        while(!q.empty())
        {
            int x = q.front().x,y = q.front().y;
            if(safe(x,y))
            {
                printf("Yes\n");
                return 0;
            }
            q.pop();
            for(int j = 1;j <= n;j++)
            {
                if(!canreach(x,y,a[j].x,a[j].y,0) || visit[j])    continue;
                visit[j] = 1;
                q.push(a[j]);
            }
        }
    }
    printf("No\n");
    return 0;
}
