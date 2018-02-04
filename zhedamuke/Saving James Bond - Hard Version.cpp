#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#define INF 0x3f3f3f3f
using namespace std;

struct pos
{
    int num,x,y,step;
}a[105],temp;
int n,d,visit[105];
queue<struct pos> q;
int pre[105] = {0};

bool cmp(struct pos X,struct pos Y)
{
	return X.x*X.x+X.y*X.y < Y.x*Y.x+Y.y*Y.y;
}

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
        printf("1\n");
        return 0;
    }
    for(int i = 1;i <= n;i++)	scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i <= n;i++)	a[i].num = i;
    for(int i = 1;i <= n;i++)
    {
        if(!canreach(0,0,a[i].x,a[i].y,7))    break;
        a[i].step = 2;
        q.push(a[i]);
        visit[i] = 1;
    }
    int ans = -1;
    while(!q.empty())
    {
        int x = q.front().x,y = q.front().y,num = q.front().num;
        if(safe(x,y))
        {
            ans = num;
            break; 
        }
        q.pop();
        for(int j = 1;j <= n;j++)
        {
            if(!canreach(x,y,a[j].x,a[j].y,0) || visit[j])    continue;
            visit[j] = 1;
            pre[j] = num;
            q.push(a[j]);
        }
    }
    if(ans == -1)	printf("0\n");
    else
    {
    	stack<struct pos> s;
    	int cnt = 1;
    	while(ans)
    	{
    		s.push(a[ans]);
    		ans = pre[ans];
    		cnt++;
		}
		printf("%d\n",cnt);
		while(!s.empty())
		{
			printf("%d %d\n",s.top().x,s.top().y);
			s.pop();
		}
	}
    return 0;
}
