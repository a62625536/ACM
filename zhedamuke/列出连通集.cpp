#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

queue<int> q;
int a[15][15] = {0},visit[15],n,e;

void dfs(int x)
{
    visit[x] = 1;
    for(int i = 0;i < n;i++)
    {
        if(a[x][i] == 0 || visit[i]) continue;
        printf("%d ",i);
        dfs(i);
    }
}

int main()
{
    scanf("%d%d",&n,&e);
    for(int i = 1;i <= e;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y] = a[y][x] = 1;
    }
    memset(visit,0,sizeof(visit));
    for(int i = 0;i < n;i++)
    {
        if(!visit[i])
        {
            printf("{ %d ",i);
            dfs(i);
            printf("}\n");
        }
    }
    memset(visit,0,sizeof(visit));
    for(int i = 0;i < n;i++)
    {
        if(visit[i])    continue;
        while(!q.empty())   q.pop();
        q.push(i);
        visit[i] = 1;
        printf("{ %d ",i);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            for(int j = 0;j < n;j++)
            {
                if(a[now][j] == 0 || visit[j])   continue;
                q.push(j);
                visit[j] = 1;
                printf("%d ",j);
            }
        }
        printf("}\n");
    }
    return 0;
}
