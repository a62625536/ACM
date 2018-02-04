#include<bits/stdc++.h>
using namespace std;

int n,m,k,ans[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
    {
        int minn = 100,maxx = 0,sum = 0;
        for(int j = 1;j <= m;j++)
        {
            int x;
            cin >> x;
            sum += x;
            minn = min(x,minn);
            maxx = max(x,maxx);
        }
        sum -= minn;
        sum -= maxx;
        ans[i] = sum;
    }
    sort(ans+1,ans+1+n);
    reverse(ans+1,ans+1+n);
    cout << fixed << setprecision(3) << (double)ans[k]/(m-2);
    for(int i = k-1;i >= 1;i--) cout << " " << fixed << setprecision(3) << (double)ans[i]/(m-2);
    cout << endl;
    return 0;
}
