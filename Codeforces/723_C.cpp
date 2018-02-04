#include<bits/stdc++.h>
using namespace std;

int n,m,a[2005],b[2005] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] <= m)   b[a[i]]++;
    }
    int ans = n/m,cnt = 0,now = 1;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] <= m && b[a[i]] <= ans) continue;
        while(b[now] >= ans)    now++;
        if(now == m+1)  break;
        if(a[i] <= m)   b[a[i]]--;
        a[i] = now;
        b[now]++;
        cnt++;
    }
    cout << ans << " " << cnt << endl;
    for(int i = 1;i <= n;i++)   cout << a[i] << " ";
    cout << endl;
	return 0;
 }

