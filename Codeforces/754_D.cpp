#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct xx
{
    int l,r,id;
}a[300005];
int n,k;
priority_queue< int,vector<int>,greater<int> > q;

bool cmp(xx a,xx b)
{
    return a.l < b.l;
}

int main()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp);
    int maxx = 0,ans;
    for(int i = 1;i <= n;i++)
    {
        q.push(a[i].r);
        if(q.size() < k)    continue;
        if(q.size() > k)    q.pop();
        if(q.top()-a[i].l+1 > maxx)
        {
            maxx = q.top()-a[i].l+1;
            ans = a[i].l;
        }
    }
    cout << maxx << endl;
    if(maxx == 0)
    {
        for(int i = 1;i <= k;i++)    cout << i << " ";
    }
    else
    {
        int t = ans+maxx-1,cnt = 1;
        for(int i = 1;i <= n && cnt <= k;i++)
        {
            if(a[i].l <= ans && a[i].r >= t)
            {
                cout << a[i].id << " ";
                cnt++;
            }
        }
    }
    cout << endl;
    return 0;
}
