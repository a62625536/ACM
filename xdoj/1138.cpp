#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int a1,a2,b1,b2;

int main()
{
	while(~scanf("%d+%di %d+%di",&a1,&b1,&a2,&b2))
	{
		printf("%d+%di\n",a1+a2,b1+b2);
	}
	return 0;
}
