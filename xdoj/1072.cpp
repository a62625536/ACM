#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,dfn[10005],low[10005],num,cnt;
vector<int> v[10005];

void tarjan(int pos,int pre)
{
    dfn[pos] = low[pos] = ++num;
    for(int i = 0;i < v[pos].size();i++)
    {
        int x = v[pos][i];
        if(x == pre)  continue;
        if(dfn[x] == 0)
        {
            tarjan(x,pos);
            low[pos] = min(low[pos],low[x]);
            if(dfn[pos] < low[x])   cnt++;
        }
        else    low[pos] = min(low[pos],dfn[x]);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        num = 0;
        cnt = 0;
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)    v[i].clear();
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        tarjan(0,-1);
        printf("%d\n",cnt);
    }
    return 0;
}
