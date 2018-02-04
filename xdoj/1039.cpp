#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct  yy
{
    int num,y;
    friend bool operator<(yy A,yy B)
    {
        return A.y > B.y;
    }
}y;
struct zz
{
    int num,z;
    friend bool operator<(zz A,zz B)
    {
        return A.z > B.z;
    }
}z;

struct xx
{
    int x,last,next;
}a[1005];
int eat[1005],die[1005],n,m,live,turn;
priority_queue<yy> qy;
priority_queue<zz> qz;

void fun(int i)
{
    a[i].x--;
    if(a[i].x == 0)
    {
        die[i] = 1;
        eat[i] = 0;
        live--;
        a[a[i].last].next = a[i].next;
        a[a[i].next].last = a[i].last;
    }
}

void eatt(int num)
{
    if(!eat[num])   fun(num);
    for(int i = 1;i <= n;i++)
    {
        if(eat[i])  fun(i);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        while(!qy.empty())  qy.pop();
        while(!qz.empty())  qz.pop();
        memset(die,0,sizeof(die));
        memset(eat,0,sizeof(eat));
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
        {
            a[i].last = i-1;
            a[i].next = i+1;
            scanf("%d",&a[i].x);
        }
        a[1].last = n;
        a[n].next = 1;
        for(int i = 1;i <= n;i++)
        {
            y.num = i;
            scanf("%d",&y.y);
            qy.push(y);
        }
        for(int i = 1;i <= n;i++)
        {
            z.num = i;
            scanf("%d",&z.z);
            qz.push(z);
        }
        turn = 1,live = n;
        while(m--)
        {
            int card,now;
            scanf("%d",&card);
            if(n == 1)    break;
            switch(card)
            {
                case 1:
                    now = qy.top().num;
                    while(die[now])
                    {
                        qy.pop();
                        now = qy.top().num;
                    }
                    eatt(now);
                    break;
                case 2:
                    now = qz.top().num;
                    while(die[now])
                    {
                        qz.pop();
                        now = qz.top().num;
                    }
                    eatt(now);
                    break;
                case 3:
                    eat[turn] = 1;
                    break;
                case 4:
                    eatt(a[turn].last);
                    break;
                case 5:
                    eatt(a[turn].next);
                    break;
                case 6:
                    eatt(turn);
                    break;
            }
            if(live == 0)   break;
            turn = a[turn].next;
            while(die[turn])   turn = a[turn].next;
            if(live == 1)   break;
        }
        for(int i = 1;i <= m;i++)
        {
            int card;
            scanf("%d",&card);
        }
        switch(live)
        {
            case 0:
                printf("0\n");
                break;
            case 1:
                printf("%d\n",turn);
                break;
            default:
                printf("-1\n");
                break;
        }
    }
    return 0;
}
