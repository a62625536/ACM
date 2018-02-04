#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> P;
char a[4][105];
int n,k;
bool vis[4][105];

int bfs(int s)
{
    memset(vis,0,sizeof(vis));
    queue<P> q;
    q.push(P(s,1));
    while(!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        if(isalpha(a[x][++y]))    continue;
        for(int i = -1;i <= 1;i++)
        {
            int xx = x+i;
            if(xx < 1 || xx > 3)    continue;
            if(isalpha(a[xx][y]) || isalpha(a[xx][y+1]) || isalpha(a[xx][y+2]))   continue;
            int yy = y+2;
            if(vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            if(yy >= n) return 1;
            q.push(P(xx,yy));
        }
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        int s;
        scanf("%d%d",&n,&k);
        for(int i = 1;i <= 3;i++)
        {
            scanf("%s",a[i]+1);
            if(a[i][1] == 's')  s = i;
        }
        if(bfs(s))  printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}
