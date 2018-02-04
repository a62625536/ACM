#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,l,r,sum[10005],t[10005];

int main()
{
	ios::sync_with_stdio(false);
    while(cin >> n >> l >> r)
    {
        memset(sum,0,sizeof(sum));
        memset(t,0,sizeof(t));
        t[0] = 1;
        sum[0] = 1;
        while(n--)
        {
            int c,a;
            cin >> c >> a;
            for(int i = 0;i+c <= r;i++)
            {
                t[i+c] = (t[i]+t[i+c])%MOD;
                int tt = i+(a+1)*c;
                if(tt <= r) t[tt] = (t[tt]-sum[i]+MOD)%MOD;
            }
            memcpy(sum,t,(r+1)*sizeof(int));
        }
        for(int i = l+1;i <= r;i++) sum[i] = (sum[i-1]+sum[i])%MOD;
        cout << sum[r] << endl;
    }
    return 0;
}
