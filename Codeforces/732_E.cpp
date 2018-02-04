#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

struct ss
{
    int s,id;
    friend bool operator <(ss X,ss Y)
    {
        return X.s < Y.s;
    }
}s[200005];

struct pp
{
    int p,id;
    pp(){};
    pp(int a,int b):p(a),id(b){};
    friend bool operator <(pp X,pp Y)
    {
        return X.p < Y.p;
    }
}p[200005];

int n,m,a[200005] = {0},ans[200005] = {0};
bool used[200005],ok[200005];
map<int,int> mp;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&p[i].p);
        p[i].id = i;
        mp[p[i].p]++;
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&s[i].s);
        s[i].id = i;
    }
    sort(p+1,p+n+1);
    sort(s+1,s+m+1);
    int sum = 0,cnt = 0;
    for(int i = 0;i < 31;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(used[j] || !mp[s[j].s]) continue;
            int t = lower_bound(p+1,p+1+n,pp(s[j].s,0))-p+mp[s[j].s]-1;
            mp[s[j].s]--;
            ok[t] = 1;
            used[j] = 1;
            cnt++;
            sum += i;
            a[s[j].id] = i;
            ans[p[t].id] = s[j].id;
        }
        for(int j = 1;j <= m;j++)
        {
            if(used[j]) continue;
            s[j].s = s[j].s/2+s[j].s%2;
        }
    }
    printf("%d %d\n",cnt,sum);
    for(int i = 1;i <= m;i++)   printf("%d ",a[i]);
    printf("\n");
    for(int i = 1;i <= n;i++)   printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
