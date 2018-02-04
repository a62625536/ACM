#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100005],n,m,has[15];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    memset(has,0,sizeof(has));
		scanf("%d%d",&n,&m);
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			if(!has[a[i]])	has[a[i]] = 1;
		}
		int ans = 0;
		for(int i = 1;i <= m;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				if(i == j)	continue;
				if(!has[i] || !has[j])	continue;
				int sum = 0,maxx = 0,flag = 0;
				for(int k = 1;k <= n;k++)
				{
					if(a[k] == i)	sum++;
					else if(a[k] == j)
					{
						sum--;
						flag = 1;
					}
					if(sum < 0)
					{
						sum = 0;
						flag = 0;
					}
					if(flag)	maxx = max(maxx,sum);
					else	maxx = max(maxx,sum-1);
				}
				ans = max(ans,maxx);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
