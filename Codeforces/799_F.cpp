#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[200005];
int v0[200005],v1[200005],v2[200005],v3[200005];
long long sum0[200005] = {0},sum1[200005] = {0},sum2[200005] = {0},sum3[200005] = {0};
bool has1[200005] = {0},has2[200005] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int x;
    cin >> x;
    while(x--)
    {
        int xx;
        cin >> xx;
        has1[xx] = 1;
    }
    cin >> x;
    while(x--)
    {
        int xx;
        cin >> xx;
        has2[xx] = 1;
    }
    int cnt0 = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
    for(int i = 1;i <= n;i++)
    {
        if(has1[i] && has2[i])  v3[++cnt3] = a[i];
        else if(has1[i])    v1[++cnt1] = a[i];
        else if(has2[i])    v2[++cnt2] = a[i];
        else    v0[++cnt0] = a[i];
    }
    sort(v0+1,v0+1+cnt0);
    sort(v1+1,v1+1+cnt1);
    sort(v2+1,v2+1+cnt2);
    sort(v3+1,v3+1+cnt3);
    for(int i = 1;i <= cnt0;i++)    sum0[i] = sum0[i-1]+v0[i];
    for(int i = 1;i <= cnt1;i++)    sum1[i] = sum1[i-1]+v1[i];
    for(int i = 1;i <= cnt2;i++)    sum2[i] = sum2[i-1]+v2[i];
    for(int i = 1;i <= cnt3;i++)    sum3[i] = sum3[i-1]+v3[i];
    long long ans = 1e18;
    int t1 = 0,t2 = 0;
    for(int i = min(cnt3,m);i >= 0;i--)
    {
        t1 = max(t1,k-i),t2 = max(t2,k-i);
        if(t1+t2+i > m || t1 > cnt1 || t2 > cnt2)   break;
        if(cnt0+cnt1+cnt2+i < m)    break;
        int t0 = 0;
        while(t0+t1+t2+i < m)
        {
            int t = m-t1-t2-i;
            if(cnt0 >= t && (t1 == cnt1 || v0[t] <= v1[t1+1]) && (t2 == cnt2 || v0[t] <= v2[t2+1])) {t0 = t;break;}
            else if(t1 < cnt1 && (t2 == cnt2 || v1[t1+1] <= v2[t2+1]))  t1++;
            else    t2++;
        }
        ans = min(ans,sum0[t0]+sum1[t1]+sum2[t2]+sum3[i]);
    }
    if(ans == 1e18) cout << -1 << endl;
    else    cout << ans << endl;
    return 0;
}
