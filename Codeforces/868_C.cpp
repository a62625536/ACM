#include<bits/stdc++.h>
using namespace std;

int n,k,ok[20] = {0},a[5];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= k;j++)   cin >> a[j];
        ok[a[1]+a[2]*2+a[3]*4+a[4]*8] = 1;
    }
    for(int i = 0;i < (1<<k);i++)
    {
        for(int j = 0;j < (1<<k);j++)
        {
            if(i&j) continue;
            if(ok[i] && ok[j])
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
