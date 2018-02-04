#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n,k;

LL euler(LL n)
{
    LL ret=n;
    for(LL i=2; i*i<= n; i++)
        if(n%i==0)
        {
            ret-=ret/i;
            while(n%i==0) n/= i;
        }
    if(n>1) ret-=ret/n;
    return ret;
}

int main()
{
    cin >> n >> k;
    LL ans = euler(n);
    for(LL i = 2;i <= k;i++)
    {
        if(i%2) ans = euler(ans);
        if(ans == euler(ans))   break;
    }
    cout << ans%1000000007 << endl;
    return 0;
}


