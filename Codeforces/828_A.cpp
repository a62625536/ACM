#include<bits/stdc++.h>
using namespace std;

int n,a,b;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> a >> b;
	int b1 = b,b2 = 0,ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		if(x == 1)
		{
			if(a)	a--;
			else if(b1)
			{
				b1--;
				b2++;
			}
			else if(b2)	b2--;
			else	ans++;
		}
		else
		{
			if(b1)	b1--;
			else	ans += 2;
		}
	}
	cout << ans << endl;
	return 0;
}
