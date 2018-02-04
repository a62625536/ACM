#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[10] = {1,0,0,0,0,0,1,0,2,1};

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int ans = 0;
		while(n)
		{
			ans += a[n%10];
			n /= 10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
