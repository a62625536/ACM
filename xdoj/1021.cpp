#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define PI atan(1)*4
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		double x;
		scanf("%d%lf",&n,&x);
		printf("%.4lf\n",0.25*n*x*x/tan(PI/n));
	}
	return 0;
}
