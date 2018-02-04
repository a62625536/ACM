#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int n,m,k,cnt,sta[1<<18],a[45][1<<18];

void dfs(int l,int now,int pre1,int pre2)
{
    if(l == m)
    {
        sta[now] = 1;
        return;
    }
    for(int i = 0;i < k;i++)
    {
        if(i == pre1 && i == pre2)  continue;
        dfs(l+1,(now<<3)|i,pre2,i);
        dfs(l+1,(now<<3)|(i+4),pre2,i);
    }
}

bool ok(int x)
{
    int t = x%4;
    x >>= 3;
    int tt = x%4;
    if(t != tt) return 1;
    x >>= 3;
    int ttt = x%4;
    if(t != ttt)    return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m >> k)
    {
        if(n < m)   swap(n,m);
        memset(sta,0,sizeof(sta));
        memset(a,0,sizeof(a));
        cnt = 0;
        dfs(0,0,-1,-1);
        int endd = 1<<(3*m);
        for(int i = 0;i < endd;i++)
        {
            if(!sta[i])  continue;
            int flag = 0;
            for(int j = 0;j < m;j++)
            {
                if(i&(4<<(j*3)))   flag = 1;
            }
            if(!flag)   a[m][i] = 1;
        }
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                int now = i*m+j+1;
                for(int l = 0;l < endd;l++)
                {
                    if(a[now-1][l] == 0)   continue;
                    if((l&(4<<(j*3))) == 0 && (j < 2 || ok(l>>(3*j-6)))) a[now][l|(4<<(j*3))] = (a[now][l|(4<<(j*3))]+a[now-1][l])%MOD;
                    for(int t = 0;t < k;t++)
                    {
                        if(t == (l>>(j*3))%4)  continue;
                        int tt = (l-(l&(7<<(j*3))))|(t<<(j*3));
                        if(j > 1 && !ok(tt>>(3*j-6)))    continue;
                        a[now][tt] = (a[now][tt]+a[now-1][l])%MOD;
                    }
                }
            }
        }
        int t = n*m;
        int ans = 0;
        for(int i = 0;i < endd;i++) ans = (ans+a[t][i])%MOD;
        cout << ans << endl;
    }
    return 0;
}
