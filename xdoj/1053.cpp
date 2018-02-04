#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n > 0)	printf("yes\n");
		else if(n < 0)	printf("no\n");
		else	printf("light\n");
	}
	return 0;
}
