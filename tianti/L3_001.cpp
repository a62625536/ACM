#include<bits/stdc++.h>
using namespace std;

int n,m,pre[105],a[10005],dp[105];

void printff(int x)
{
    if(pre[x] == 0) cout << x;
    else
    {
        printff(pre[x]);
        cout << " " << x-pre[x];
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= m;i++)   dp[i] = -1e9;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++)
    {
        for(int j = m;j >= a[i];j--)
        {
            if(dp[j] <= dp[j-a[i]]+1)
            {
                dp[j] = dp[j-a[i]]+1;
                pre[j] = j-a[i];
            }
        }
    }
    if(dp[m] <= 0)
    {
        cout << "No Solution" << endl;
        return 0;
    }
    printff(m);
    return 0;
}
