#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

int n,num[61],temp[31],last[31];
stack<int> s;

int main()
{
	char move[61][30];
	scanf("%d",&n);
	getchar();
	int i;
	for(i = 1;i <= n*2;i++)
	{
		scanf("%s",move[i]);
		if(!strcmp(move[i],"Push"))	scanf("%d",&num[i]);
	}
	int counts = 0;
	for(int i = 1;i <= 2*n;i++)
	{
		if(!strcmp(move[i],"Push"))	s.push(num[i]);
		else
		{
			for(;counts > 0 && s.top() == last[counts-1];counts--)	printf("%d ",temp[counts-1]);
			temp[counts] = s.top();
			s.pop();
			if(!s.empty())	last[counts++] = s.top();
			else	counts++;
		}
	}
	if(n != 0)
	{
		for(;counts > 1;counts--)	printf("%d ",temp[counts-1]);
		printf("%d",temp[0]);
	}
	printf("\n");
	return 0;
}

