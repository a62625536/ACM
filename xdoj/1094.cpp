#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

void printff(int x)
{
	if(x == 1)
	{
		printf("2(0)");
		return;
	}
	if(x == 2)
	{
		printf("2");
		return; 
	}
	int sum = 1,b = -1;
	while(sum <= x)
	{
		sum *= 2;
		b++;
	}
	if(sum/2 < x)
	{
		if(sum/2 == 2)
		{
			printf("2+");
			printff(x-sum/2);
		}
		else
		{
			printf("2(");
			printff(b);
			printf(")+");
			printff(x-sum/2);
		}
	}
	else
	{
		printf("2(");
		printff(b);
		printf(")");
	}
}

int main()
{
	while(~scanf("%d",&n))
	{
		printff(n);
		putchar('\n');
	}
	return 0;
}
