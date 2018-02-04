#include <bits/stdc++.h>
using namespace std;

long long n,m,p;

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m >> p)
    {
        long long ans = 1;
        int flag = 0;
        for(int i = n-m+1;i <= n;i++)
        {
            if(!flag && i%m == 0)
            {
                ans = ans*i/m%p;
                flag = 1;
            }
            else    ans = ans*i%p;
        }
        cout << ans << endl;
    }
	return 0;
}
