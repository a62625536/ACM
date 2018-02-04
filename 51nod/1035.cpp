#include<bits/stdc++.h>
using namespace std;

int n;

int euler(long long n)
{
    int ans = 1;
    for(int i = 2;(long long)i*i <= n;i++)
    {
        if(n%i == 0)
        {
            n /= i;
            ans *= i-1;
            while(n%i == 0)
            {
                n /= i;
                ans *= i;
            }
        }
    }
    if(n > 1)     ans *= n-1;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int ans = 1,maxx = 0;
    for(int i = 1;i <= n;i++)
    {
        int t = i;
        while(t%2 == 0) t /= 2;
        while(t%5 == 0) t /= 5;
        int cnt = 0,now = 1;
        if(t != 1)
        {
            while(1)
            {
                cnt++;
                now = now*10%t;
                if(now == 1)    break;
            }
        }
        if(cnt > maxx)
        {
            ans = i;
            maxx = cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
