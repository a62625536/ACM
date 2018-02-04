#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int c[200005],d[200005] = {0},n;
vector<int> v[200005];

void dfs(int x,int pre)
{
    for(int i = 0;i < v[x].size();i++)
    {
        int t = v[x][i];
        if(t == pre)    continue;
        d[t] = d[x]+(c[x]^c[t]);
        dfs(t,x);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&c[i]);
    for(int i = 1;i < n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    int t = 1,maxx = d[1];
    for(int i = 1;i <= n;i++)
    {
        if(d[i] > maxx)
        {
            maxx = d[i];
            t = i;
        }
    }
    memset(d,0,sizeof(d));
    dfs(t,-1);
    maxx = d[1];
    for(int i = 1;i <= n;i++)
    {
        maxx = max(d[i],maxx);
    }
    printf("%d\n",(maxx+1)/2);
    return 0;
}
