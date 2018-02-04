#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v[1000005],ans;
int t[1000005],sum = 0;

int dfs(int x)
{
    int s = t[x];
    for(int i = 0;i < v[x].size();i++)
    {
        int tt = v[x][i];
        s += dfs(tt);
    }
    if(s == sum)
    {
        ans.push_back(x);
        return 0;
    }
    return s;
}

int main()
{
    scanf("%d",&n);
    int root;
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d%d",&x,&t[i]);
        v[x].push_back(i);
        if(x == 0)  root = i;
        sum += t[i];
    }
    if(sum%3)
    {
        printf("-1\n");
        return 0;
    }
    sum /= 3;
    dfs(root);
    if(ans.size() >= 3)
    {
        printf("%d %d\n",ans[0],ans[1]);
    }
    else    printf("-1\n");
    return 0;
}
