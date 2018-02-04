#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,ww,w[1005],b[1005],pre[1005],dp[1005] = {0};
vector<int> v[1005];

int findd(int x)
{
    int root = x;
    while(pre[root] != root)    root = pre[root];
    int i = x,j;
    while(pre[i] != root)
    {
        j = pre[i];
        pre[i] = root;
        i = j;
    }
    return root;
}

void join(int a,int b)
{
    int x = findd(a),y = findd(b);
    if(x != y)  pre[x] = y;
}

int main()
{
    cin >> n >> m >> ww;
    for(int i = 1;i <= n;i++)   cin >> w[i];
    for(int i = 1;i <= n;i++)   cin >> b[i];
    for(int i = 1;i <= n;i++)   pre[i] = i;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        join(x,y);
    }
    for(int i = 1;i <= n;i++)
    {
        int t = findd(i);
        v[t].push_back(i);
    }
    for(int i = 1;i <= n;i++)
    {
        if(findd(i) != i)   continue;
        for(int j = ww;j >= 0;j--)
        {
            int sumw = 0,sumb = 0;
            for(int k = 0;k < v[i].size();k++)
            {
                int t = v[i][k];
                sumw += w[t];
                sumb += b[t];
                if(j >= w[t])    dp[j] = max(dp[j],dp[j-w[t]]+b[t]);
            }
            if(j >= sumw)   dp[j] = max(dp[j],dp[j-sumw]+sumb);
        }
    }
    cout << dp[ww] << endl;
    return 0;
}
