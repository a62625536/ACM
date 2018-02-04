#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int n,m,nn,tt,a[105][2],sta[105][105],t[105][105],dir[4][2] = {-1,0,0,-1,1,0,0,1};
struct water
{
    int x,y,d,t;
    water(int _x,int _y,int _d,int _t):x(_x),y(_y),d(_d),t(_t){};
    friend bool operator <(water X,water Y)
    {
        return X.t > Y.t;
    }
};

void bfs(int x,int y)
{
    priority_queue<water> q;
    q.push(water(x,y,0,1));
    q.push(water(x,y,1,1));
    q.push(water(x,y,2,1));
    q.push(water(x,y,3,1));
    while(!q.empty())
    {
        water temp = q.top();
        q.pop();
        if(temp.t > tt) return;
        int xx = temp.x+dir[temp.d][0],yy = temp.y+dir[temp.d][1];
        if(xx < 1 || xx > n || yy < 1 || yy > m)    continue;
        if(t[xx][yy] == temp.t)    continue;
        if(sta[xx][yy] == 0)  q.push(water(xx,yy,temp.d,temp.t+1));
        else if(sta[xx][yy] == 4)
        {
            sta[xx][yy] = 0;
            t[xx][yy] = temp.t;
            q.push(water(xx,yy,0,temp.t+1));
            q.push(water(xx,yy,1,temp.t+1));
            q.push(water(xx,yy,2,temp.t+1));
            q.push(water(xx,yy,3,temp.t+1));
        }
        else    sta[xx][yy]++;
    }
}

int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&nn,&tt))
    {
        memset(sta,0,sizeof(sta));
        memset(t,0,sizeof(t));
        for(int i = 1;i <= nn;i++)
        {
            int x;
            scanf("%d%d%d",&a[i][0],&a[i][1],&x);
            sta[a[i][0]][a[i][1]] = x;
        }
        int x,y;
        scanf("%d%d",&x,&y);
        bfs(x,y);
        for(int i = 1;i <= nn;i++)
        {
            if(t[a[i][0]][a[i][1]] == 0)    printf("1 %d\n",sta[a[i][0]][a[i][1]]);
            else    printf("0 %d\n",t[a[i][0]][a[i][1]]);
        }
    }
    return 0;
}
