#include<bits/stdc++.h>
using namespace std;

int n,a[100005],l[100005],r[100005],vis[100005] = {0};
map<int,int> mp;

struct xx
{
    int x;
    xx():l(NULL),r(NULL){};
    xx *l,*r;
}*root;

void insertt(int now,xx *&p)
{
    p = new xx;
    p->x = a[now];
    if(l[now] > 0)  insertt(l[now],p->l);
    if(r[now] > 0)  insertt(r[now],p->r);
}

void dfs(xx *p,int ll,int rr)
{
    if(!p)  return;
    if(ll < p->x && p->x < rr)    mp[p->x] = 0;
    dfs(p->l,ll,min(p->x,rr));
    dfs(p->r,max(p->x,ll),rr);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> l[i] >> r[i];
        if(l[i] > 0)    vis[l[i]] = 1;
        if(r[i] > 0)    vis[r[i]] = 1;
        mp[a[i]]++;
    }
    root = NULL;
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])  continue;
        insertt(i,root);
    }
    dfs(root,-2e9,2e9);
    int ans = 0;
    for(map<int,int>::iterator it = mp.begin();it != mp.end();it++) ans += it->second;
    cout << ans << endl;
    return 0;
}
