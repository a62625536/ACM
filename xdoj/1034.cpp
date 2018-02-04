#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int sub = 1,ans = 1;
		while(n > sub)
		{
			n -= sub;
			ans++;
			sub *= 2;
		}
		if(n <= sub/2)	printf("%d %d\n",ans-1,sub/2);
		else	printf("%d %d\n",ans,n);
	}
	return 0;
}
