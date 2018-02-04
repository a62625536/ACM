#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct st
{
    int num,t;
}s;
deque<st> q;
int n,x;

int main()
{
    while(~scanf("%d",&n))
    {
        while(!q.empty())   q.pop_back();
        int out = 1,cnt = 1;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&x);
            switch(x)
            {
                case 1:
                    int tt;
                    scanf("%d",&tt);
                    s.t = tt-i;
                    s.num = cnt++;
                    while(!q.empty() && q.back().t <= s.t)    q.pop_back();
                    q.push_back(s);
                    break;
                case 2:
                    if(q.front().num == out++)  q.pop_front();
                    break;
                case 3:
                    printf("%d\n",q.front().t+i);
            }
        }
    }
    return 0;
}
