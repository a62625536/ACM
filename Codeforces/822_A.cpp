#include<bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
	ios::sync_with_stdio(0);
	cin >> a >> b;
	int t  = min(a,b);
	int ans = 1;
	for(int i = 1;i <= t;i++)	ans *= i;
	cout << ans << endl;
	return 0;
}
