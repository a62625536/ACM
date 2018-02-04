#include<bits/stdc++.h>
using namespace std;

long long x,y,l,r,a[105],b[105];

int main()
{
    ios::sync_with_stdio(0);
    cin >> x >> y >> l >> r;
    int cnt1 = 0,cnt2 = 0;
    a[++cnt1] = 1;
    b[++cnt2] = 1;
    while(a[cnt1] <= r/x)
    {
        a[cnt1+1] = a[cnt1]*x;
        cnt1++;
    }
    while(b[cnt2] <= r/y)
    {
        b[cnt2+1] = b[cnt2]*y;
        cnt2++;
    }
    set<long long> s;
    for(int i = 1;i <=cnt1;i++)
    {
        if(a[i] > r)    continue;
        for(int j = 1;j <= cnt2;j++)
        {
            if(b[j] > r) continue;
            if(a[i]+b[j] < l) continue;
            if(a[i]+b[j] > r) continue;
            s.insert(a[i]+b[j]);
        }
    }
    s.insert(l-1);
    s.insert(r+1);
    long long ans = 0;
    for(auto it = ++s.begin();it != s.end();it++)
    {
        long long xx = *it;
        it--;
        long long yy = *it;
        it++;
        ans = max(ans,xx-yy-1);
    }
    cout << ans << endl;
    return 0;
}
