#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct aa
{
	char name[25];
	int rating;
}a[10005];
int n;

bool cmp(aa x,aa y)
{
	if(x.rating == y.rating)	return strcmp(x.name,y.name) < 0;
	else return x.rating > y.rating;
}
int main()
{
	while(scanf("%d",&n) && n)
	{
		for(int i = 0;i < n;i++)	scanf("%s%d",a[i].name,&a[i].rating);
		sort(a,a+n,cmp);
		for(int i = 0;i < n;i++)	printf("%s %d\n",a[i].name,a[i].rating);
	}
	return 0;
}
