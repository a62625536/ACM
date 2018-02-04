#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cnt[200005] = {0},n;

int main()
{
	scanf("%d",&n);
	int temp,maxx = 0;
	while(n--)
	{
		scanf("%d",&temp);
		maxx = max(maxx,temp);
		cnt[temp]++;
	}
	for(int i = 2;i <= maxx;i++)	cnt[i] += cnt[i-1];
	long long ans = 0,tempmax;
	for(int i = 1;i <= maxx;i++)
	{
		if(cnt[i] != cnt[i-1])
		{
			tempmax = 0;
			for(int j = i;j <= maxx;j += i)	tempmax += (long long)j*(cnt[min(j+i-1,maxx)]-cnt[j-1]);
			ans = max(tempmax,ans);
		}
		
	}
	printf("%I64d\n",ans);
	return 0;
}
