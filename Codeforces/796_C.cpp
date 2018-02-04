#include<bits/stdc++.h>
using namespace std;

int n,a[300005];
vector<int> v[300005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt1,cnt2 = 0,maxx = -1e9;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(maxx < a[i])
        {
            maxx = a[i];
            cnt1 = 1;
        }
        else if(maxx == a[i])    cnt1++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == maxx-1)  cnt2++;
    }
    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = 2e9;
    for(int i = 1;i <= n;i++)
    {
        int now = 0,sum1 = 0,sum2 = 0;
        if(a[i] == maxx)   now++;
        for(int j = 0;j < v[i].size();j++)
        {
            int t = v[i][j];
            if(a[t] == maxx)    sum1++;
            if(a[t] == maxx-1)  sum2++;
        }
        if(now+sum1 == cnt1)
        {
            if(cnt1 == 1 && now == 1 && sum2 == cnt2)   ans = min(ans,maxx);
            else    ans = min(ans,maxx+1);
        }
        else    ans = min(ans,maxx+2);
    }
    cout << ans << endl;
    return 0;
}
