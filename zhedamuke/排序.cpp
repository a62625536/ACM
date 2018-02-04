#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[100005],n;

int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	printf("%d",a[1]);
	for(int i = 2;i <= n;i++)	printf(" %d",a[i]);
	printf("\n");
	return 0;
}
