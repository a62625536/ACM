#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[55][55],ans[2505],n,m;

int main() 
{
	while(~scanf("%d%d",&n,&m))
	{
		int total = n*m;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)	scanf("%d",&a[i][j]);
		}
		int now = 2,x = 1,y = 1;
		ans[1] = a[1][1];
		while(now <= total)
		{
			if(x < n)	ans[now++] = a[++x][y];
			else	ans[now++] = a[x][++y];
			while(x > 1 && y < m)	ans[now++] = a[--x][++y];
			if(y < m)	ans[now++] = a[x][++y];
			else	ans[now++] = a[++x][y];
			while(x < n && y > 1)	ans[now++] = a[++x][--y];
		}
		printf("%d",ans[1]);
		for(int i = 2;i <= total;i++)	printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
