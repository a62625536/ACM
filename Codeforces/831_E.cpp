#include<bits/stdc++.h>
using namespace std;

int n,a[100005],tree[100005] = {0};
set<int> s[100005];

inline int lowbit(int x)
{
    return x&-x;
}

void update(int pos,int x)
{
    while(pos <= n)
    {
        tree[pos] += x;
        pos += lowbit(pos);
    }
}

int getsum(int pos)
{
    int sum = 0;
    while(pos > 0)
    {
        sum += tree[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
         cin >> a[i];
         s[a[i]].insert(i);
         update(i,1);
    }
    sort(a+1,a+1+n);
    int now = 0;
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        int t = a[i];
        auto it = s[t].lower_bound(now);
        if(it == s[t].end())
        {
            ans += getsum(n)-getsum(now);
            it = s[t].lower_bound(0);
            now = 0;
        }
        ans += getsum(*it)-getsum(now);
        now = *it;
        update(*it,-1);
        s[t].erase(it);
    }
    cout << ans << endl;
    return 0;
}
