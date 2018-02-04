#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a;

int main()
{
	int flag = 1;
	scanf("%d",&n);
	int last = 0;
	for(int i = 1;i < n;i++)
	{
		scanf("%d",&a);
		if(flag == 0)	continue;
		if(last > a)	flag = 0;
		a -= last;
		last = a%2;
	}
	if(flag)
	{
		scanf("%d",&a);
		if(last > a)	flag = 0;
		if(flag)
		{
			a -= last;
			if(a%2)	flag = 0;
		}
	}
	if(flag)	printf("YES\n");
	else		printf("NO\n");
	return 0;
}
