#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],ans[105] = {0};
map<int,int> used;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++)  cin >> a[i];
    for(int i = 2;i <= m;i++)
    {
        if(ans[a[i-1]])
        {
            if((a[i-1]+ans[a[i-1]]-1)%n+1 != a[i])
            {
                cout << -1 << endl;
                return 0;
            }
        }
        else
        {
            int t = a[i]-a[i-1];
            if(t <= 0)   t += n;
            if(used.count(t))
            {
                cout << -1 << endl;
                return 0;
            }
            ans[a[i-1]] = t;
            used[t] = 1;
        }
    }
    int now = 1;
    for(int i = 1;i <= n;i++)
    {
        if(ans[i])  cout << ans[i] << " ";
        else
        {
            while(used.count(now))  now++;
            cout << now << " ";
            used[now] = 1;
        }
    }
    return 0;
}
