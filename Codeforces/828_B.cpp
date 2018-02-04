#include<bits/stdc++.h>
using namespace std;

int n,m;
string s[105];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i];
		s[i] = ' '+s[i];
	}
	int l = 105,r = 0,h = 0,d = 105,cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(s[i][j] == 'W')	continue;
			cnt++;
			l = min(l,j);
			r = max(r,j);
			h = max(h,i);
			d = min(d,i);
		}
	}
	int ans = max(r-l+1,h-d+1);
	if(ans <= 0)
	{
		cout << 1 << endl;
		return 0;
	}
	if(ans > n || ans > m)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << ans*ans-cnt << endl;
	return 0;
}
