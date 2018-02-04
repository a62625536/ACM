#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int n,m,q,a[1000005],r[1000005],c[1000005];
char s[1000005];

int main()
{
	int num = 1;
	while(~scanf("%d%d",&n,&m))
	{
		printf("Case #%d:\n",num++);
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++)	r[i] = i;
		for(int i = 1;i <= m;i++)	c[i] = i;
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%s",s);
			for(int j = 0;j < m;j++)
			{
				if(s[j] == 'T')			a[++cnt] = 1;
				else if(s[j] == 'i')	a[++cnt] = 2;
				else	a[++cnt] = 0;
			}	
		}
		scanf("%d",&q);
		while(q--)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x == 1)
			{
				int temp = (r[y]-1)*m+c[z];
				switch(a[temp])
				{
					case 0:	printf("Empty\n");
							break;
					case 1:	printf("Tree\n");
							break;
					case 2:	printf("Phone\n");
							break;
				}
			}
			else if(x == 2)	swap(r[y],r[z]);
			else if(x == 3)	swap(c[y],c[z]);
		}
	}
	return 0;
}
