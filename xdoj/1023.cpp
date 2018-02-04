#include<bits/stdc++.h>
using namespace std;

int n,m,r[100005];
struct city
{
	int l,id;
	friend bool operator <(city x,city y)
	{
	    return x.l < y.l;
	}
}a[100005];

int main()
{
    ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d",&n);
		for(int i = 1;i <= n;i++)	scanf("%d%d%d",&a[i].l,&r[i],&a[i].id);
		sort(a+1,a+n+1);
		sort(r+1,r+n+1);
		scanf("%d",&m);
		while(m--)
		{
			int ip;
			scanf("%d",&ip);
			int ans = lower_bound(r+1,r+1+n,ip)-r;
			if(ans == n+1 || ip < a[ans].l)	printf("-1\n");
			else	printf("%d\n",a[ans].id);
		}
	}
	return 0;
}
