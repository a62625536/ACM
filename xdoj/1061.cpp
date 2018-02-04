#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int a1,a2,b1,b2;
	while(~scanf("%d/%d %d/%d",&a1,&a2,&b1,&b2))
	{
		int x = a1*b2+a2*b1,y = a2*b2;
		int g = gcd(x,y);
		printf("%d/%d\n",x/g,y/g);
	}
	return 0;
}
