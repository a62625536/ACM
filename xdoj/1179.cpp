#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[5005],ans[10000005] = {0},n,s,q;
int main()
{
    memset(ans,0x3f,sizeof(ans));
	scanf("%d%d",&n,&s);
	for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        for(int j = 1;j <= s;j++)   ans[a[i]*j] = min(ans[a[i]*j],j);
    }

	scanf("%d",&q);
	while(q--)
	{
		int t,x = INF;
		scanf("%d",&t);
		for(int i = 1;i <= n;i++)
        {
            int endd = min(s,t/a[i]);
            for(int j = 1;j <= endd;j++)
            {
                int left = t-j*a[i];
                if(left == 0)   x = min(x,j);
                else if(ans[left] && ans[left]+j <= s)  x = min(x,ans[left]+j);
            }
        }
        if(x == INF)    printf("-1\n");
        else    printf("%d\n",x);
	}
	return 0;
}
