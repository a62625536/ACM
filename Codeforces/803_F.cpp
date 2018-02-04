#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,cnt[100005] = {0},ans[100005],two[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        for(int i = 1;i*i <= x;i++)
        {
            if(x%i == 0)
            {
                cnt[i]++;
                if(i*i != x)    cnt[x/i]++;
            }
        }
    }
    two[0] = 1;
    for(int i = 1;i <= 100000;i++)  two[i] = two[i-1]*2%MOD;
    for(int i = 1;i <= 100000;i++)  ans[i] = two[cnt[i]]-1;
    for(int i = 100000;i >= 1;i--)
    {
        for(int j = i*2;j <= 100000;j += i) ans[i] = (ans[i]-ans[j]+MOD)%MOD;
    }
    cout << ans[1] << endl;
    return 0;
}
