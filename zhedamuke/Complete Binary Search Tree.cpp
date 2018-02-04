#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int a[2005],n,ans[2005];
queue<int> q;

void q_push(int x)
{
	if(x <= n)
	{
		q_push(2*x);
		q.push(x);
		q_push(2*x+1);	
	}
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++)	scanf("%d",&a[i]);
	sort(a,a+n);
	q_push(1);
	for(int i = 0;i < n;i++)
	{
		ans[q.front()] = a[i];
		q.pop();
	}
	int flag = 1;
	for(int i = 1;i <= n;i++)
	{
		if(flag)
		{
			printf("%d",ans[i]);
			flag = 0;
		}
		else	printf(" %d",ans[i]);
	}
	return 0;
}
