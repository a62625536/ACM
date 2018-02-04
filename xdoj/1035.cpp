#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int a[10][10];
int x[9] = {1,1,1,4,4,4,7,7,7},y[9] = {1,4,7,1,4,7,1,4,7};

set<int> s;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int flag = 1;
		for(int i = 1;i <= 9;i++)
		{
			s.clear();
			for(int j = 1;j <= 9;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j] == 0 || a[i][j] > 9)	flag = 0;
				s.insert(a[i][j]);
			}
			if(s.size() != 9)	flag = 0;
		}
		for(int j = 1;j <= 9;j++)
		{
			s.clear();
			for(int i = 1;i <= 9;i++)	s.insert(a[i][j]);
			if(s.size() != 9)	flag = 0;
		}
		for(int k = 0;k < 9;k++)
		{
			s.clear();
			for(int i = x[k],cnt1 = 0;cnt1 < 3;i++,cnt1++)
			{
				for(int j = y[k],cnt2 = 0;cnt2 < 3;j++,cnt2++)	s.insert(a[i][j]);
			}
			if(s.size() != 9)	flag = 0;
		}
		there:
		if(flag)	printf("yes\n");
		else		printf("no\n");
	}
	return 0;
} 
