#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    ios::sync_with_stdio(false);
	while(cin >> n >> m)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				ans += (i+j)/__gcd(i,j);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
