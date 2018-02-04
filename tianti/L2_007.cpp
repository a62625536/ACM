#include<bits/stdc++.h>
using namespace std;

int n,pre[10005],num[10005],v[10005],people[10005] = {0},has[10005] = {0},ok[10005] = {0},ans1[10005];
struct xx
{
    int id,num;
    double x1,x2;
    friend bool operator <(xx a,xx b)
    {
        if(abs(a.x2-b.x2) > 1e-6)  return a.x2 > b.x2;
        return a.id < b.id;
    }
}ans2[10005];

int findd(int x)
{
    return x == pre[x]?x:pre[x] = findd(pre[x]);
}

void join(int x,int y)
{
    int a = findd(x),b = findd(y);
    if(a != b)  pre[a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0;i <= 10000;i++)   pre[i] = i;
    for(int i = 1;i <= n;i++)
    {
        int a,b,c,k,x;
        cin >> a >> b >> c >> k;
        has[a] = 1;
        if(b != -1)
        {
            join(a,b);
            has[b] = 1;
        }
        if(c != -1)
        {
            join(a,c);
            has[c] = 1;
        }
        while(k--)
        {
            cin >> x;
            has[x] = 1;
            join(a,x);
        }
        cin >> num[a] >> v[a];
    }
    int cnt = 0;
    for(int i = 0;i < 10000;i++)
    {
        if(has[i])
        {
            if(!ok[findd(i)])
            {
                ans1[++cnt] = i;
                ok[findd(i)] = 1;
            }
            if(findd(i) != i)
            {
                num[findd(i)] += num[i];
                v[findd(i)] += v[i];
            }
            people[findd(i)]++;
        }
    }
    for(int i = 1;i <= cnt;i++)
    {
        int t = ans1[i];
        int tt = findd(t);
        ans2[i].id = ans1[i];
        ans2[i].num = people[tt];
        ans2[i].x1 = (double)num[tt]/people[tt];
        ans2[i].x2 = (double)v[tt]/people[tt];
    }
    sort(ans2+1,ans2+1+cnt);
    cout << cnt << endl;
    for(int i = 1;i <= cnt;i++)
    {
        printf("%04d %d %.3f %.3f\n",ans2[i].id,ans2[i].num,ans2[i].x1,ans2[i].x2);
    }
    return 0;
}
