#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		int cnt = 0;
		while(n > 1)
		{
			n = n/2+n%2;
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
