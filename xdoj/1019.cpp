#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int f(int x)
{
	int now = 5,ans = 0;
	while(now <= x)
	{
		ans += x/now;
		now *= 5;
	}
	return ans;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans = n*4;
		while(f(ans) < n)	ans++;
		if(f(ans) == n)	printf("%d\n",ans);
		else	printf("No solution\n");
	}
	return 0;
}
