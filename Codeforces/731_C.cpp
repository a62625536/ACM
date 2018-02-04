#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,k,c[200005],l,r,pre[200005];
vector<int> v[200005];

int findd(int x)
{
    int root = x;
    while(pre[root] != root)    root = pre[root];
    int i = x,j;
    while(pre[i] != root)
    {
        j = pre[i];
        pre[i] = root;
        i = j;
    }
    return root;
}
void join(int a,int b)
{
    int x = findd(a),y = findd(b);
    if(x != y)  pre[x] = y;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&c[i]);
		pre[i] = i;
	}
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d",&l,&r);
		join(l,r);
	}
	for(int i = 1;i <= n;i++)	v[findd(i)].push_back(c[i]);
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(!v[i].size())	continue;
		sort(v[i].begin(),v[i].end());
		int endd = v[i].size(),maxx = 0;
		for(int j = 0,now = 0;j < endd;++now,j = now)
		{
			while(now < endd-1 && v[i][now+1] == v[i][j])	now++;
			maxx = max(maxx,now-j+1);
		}
		ans += endd-maxx;
	}
	printf("%d\n",ans);
	return 0;
}
