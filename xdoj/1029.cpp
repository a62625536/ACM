#include<bits/stdc++.h>
using namespace std;

int n;

long long PowerMod(int a, int b, int c)
{
	long long ans = 1;
	a = a%c;
	while(b > 0)
	{
		if(b % 2 == 1)  ans = (ans*a)%c;
		b = b/2;
		a = (a*a)%c;
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		double x = log10(2)*n;
		int ans = pow(10,x-(int)x)+1e-6;
		cout << ans << " " << PowerMod(2,n,10) << endl;
	}
	return 0;
}
