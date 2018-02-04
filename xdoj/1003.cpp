#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int change1(char a)
{
	switch(a)
	{
		case 'A':return 10;
		case 'B':return 11;
		case 'C':return 12;
		case 'D':return 13;
		case 'E':return 14;
		case 'F':return 15;
		default	:return a-'0';
	}
}

char change2(int a)
{
	switch(a)
	{
		case 10:return 'A';
		case 11:return 'B';
		case 12:return 'C';
		case 13:return 'D';
		case 14:return 'E';
		case 15:return 'F';
		default:return a+'0'; 
	}
}

char s1[100],s2[100];
int n,ans[100];

int main()
{
	while(~scanf("%d",&n))
	{
		scanf("%s%s",s1,s2);
		int p1 = strlen(s1)-1,p2 = strlen(s2)-1;
		int cnt = 0,temp = 0;
		while(p1 >= 0 && p2 >= 0)
		{
			int now = change1(s1[p1])+change1(s2[p2])+temp;
			ans[++cnt] = now%n;
			temp = now/n;
			p1--;
			p2--;
		}
		while(p1 >= 0)
		{
			int now = change1(s1[p1])+temp;
			ans[++cnt] = now%n;
			temp = now/n;
			p1--;
		}
		while(p2 >= 0)
		{
			int now = change1(s2[p2])+temp;
			ans[++cnt] = now%n;
			temp = now/n;
			p2--;
		}
		if(temp)	ans[++cnt] = temp;
		for(int i = cnt;i > 0;i--)	putchar(change2(ans[i]));
		putchar('\n');
	}
	return 0;
}
