#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;

int main(int argc, char const *argv[])
{
	cin >> n >> k;
	int x = 240-k,ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(x >= 5*i)
		{
			ans++;
			x -= 5*i;
		}
	}
	cout << ans << endl;
	return 0;
}