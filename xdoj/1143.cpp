#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[10],vis[10],num[10],ans;

int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}

bool ok(int x,int z)
{
    if(x == 1)  return 1;
    if(x > 3 && gcd(z,num[x-3]) != 1)   return 0;
    if(x%3 != 1 && gcd(z,num[x-1]) != 1)    return 0;
    return 1;
}

void dfs(int x)
{
    if(x == 9)
    {
        ans++;
        return;
    }
    for(int i = 1;i <= 9;i++)
    {
        if(vis[i])  continue;
        if(ok(x+1,a[i]))
        {
            vis[i] = 1;
            num[x+1] = a[i];
            dfs(x+1);
            vis[i] = 0;
        }
    }
}
int main()
{
    while(~scanf("%d",&a[1]))
    {
        for(int i = 2;i <= 9;i++)   scanf("%d",&a[i]);
        ans = 0;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
