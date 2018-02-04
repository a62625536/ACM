#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,cnt = 0,a[200005],b[200005],sta[200005],ans[200005] = {0};
long long dis[200005];
vector<int> v[200005];

void dfs(int x,long long deep)
{
    sta[++cnt] = x;
    dis[x] = deep;
    for(int i = 0;i < v[x].size();i++)
    {
        int t = v[x][i];
        dfs(t,dis[x]+b[t]);
        ans[x] += ans[t]+1;
    }
    int l = 0,r = cnt-1;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(dis[x]-dis[sta[mid]] > a[x]) l = mid;
        else    r = mid-1;
    }
    ans[sta[l]]--;
    cnt--;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    for(int i = 2;i <= n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(i);
        b[i] = y;
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++)   printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
