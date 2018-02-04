#include<bits/stdc++.h>
using namespace std;

int n,k;
char ans[1000005];

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        ans[n] = 0;
        if(n%2 == 0 && k%2 == 1 || 9*n < k || n > 1 && k < 2)
        {
            cout << -1 << endl;
            continue;
        }
        for(int i = 0,j = n-1;i < j;i++,j--)
        {
            if(k >= 18)
            {
                k -= 18;
                ans[i] = '9';
                ans[j] = '9';
            }
            else
            {
                int t = k/2;
                k -= 2*t;
                ans[i] = t+'0';
                ans[j] = t+'0';
            }
        }
        if(n%2) ans[n/2] = k+'0';
        cout << ans << endl;

    }
    return 0;
}
