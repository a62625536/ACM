#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,k,c[1005],pre[1005],cnt[1005],pos[1005] = {0};

int findd(int x)
{
    return x == pre[x]?x:pre[x] = findd(pre[x]);
}

void join(int a,int b)
{
    int x = findd(a),y = findd(b);
    if(x != y)
    {
        pre[x] = y;
        cnt[y] += cnt[x];
    }
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
    {
        pre[i] = i;
        cnt[i] = 1;
    }
    for(int i = 1;i <= k;i++)   cin >> c[i];
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        cin >> x >> y;
        join(x,y);
    }
    int ans = -m,maxx = 0,sum = 0;
    for(int i = 1;i <= k;i++)   pos[findd(c[i])] = 1;
    for(int i = 1;i <= n ;i++)
    {
        if(findd(i) != i)   continue;
        if(pos[i])
        {
            maxx = max(maxx,cnt[i]);
            ans += cnt[i]*(cnt[i]-1)/2;
        }
        else    sum += cnt[i];
    }
    ans += sum*(sum-1)/2+maxx*sum;
    cout << ans << endl;
    return 0;
}
