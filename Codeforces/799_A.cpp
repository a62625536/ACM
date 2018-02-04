#include<bits/stdc++.h>
using namespace std;

int n,t,k,d;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> t >> k >> d;
    int tt = n/k;
    if(n%k) tt++;
    int sum1 = tt*t;
    int t1 = 0,t2 = d,now = 0;
    while(now < tt)
    {
        if(t1 < t2) t1 += t;
        else    t2 += t;
        now++;
    }
    int sum2 = max(t1,t2);
    if(sum1 > sum2) cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
