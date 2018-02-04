#include<bits/stdc++.h>
using namespace std;

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
	int a,b,c;
	while(cin >> a >> b >> c)   cout << PowerMod(a,b,c) << endl;
	return 0;
}
