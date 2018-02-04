#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

char a[10][2],str[5];
int noroot[10] = {0};

int main()
{
	int n,i;
	scanf("%d",&n);
	getchar();
	for(int i = 0;i <n;i++)
	{
	    gets(str);
		a[i][0] = str[0];
		a[i][1] = str[2];
		if(a[i][0] != '-')	noroot[a[i][0]-'0'] = 1;
		if(a[i][1] != '-')	noroot[a[i][1]-'0'] = 1;
	}
	if(n == 0)
    {
        printf("\n");
        return 0;
    }
    if(n == 1)
    {
        printf("0\n");
        return 0;
    }
	int root;
	for(i = 0;i < 10;i++)
	{
		if(noroot[i] == 0 && (a[i][0] != '-' || a[i][1] != '-'))
		{
			root = i;
			break;
		}
	}
	queue<int> q;
	q.push(i);
	int flag = 1;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		if(a[now][0] == '-' && a[now][1] == '-')
		{
			if(flag)	printf("%d",now);
			else		printf(" %d",now);
			flag = 0;
		}
		else
		{
			if(a[now][0] != '-')	q.push(a[now][0]-'0');
			if(a[now][1] != '-')	q.push(a[now][1]-'0');
		}
	}
	printf("\n");
	return 0;
}

