#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;
int nextt[200005],lastt[200005];

int main()
{
	while(~scanf("%d%d",&n,&k))
    {
        for(int i = 1;i < n;i++)	nextt[i] = i+1;
        for(int i = 2;i <= n;i++)	lastt[i] = i-1;
        nextt[n] = 1;
        lastt[1] = n;
        printf("%d",k);
        nextt[lastt[k]] = nextt[k];
        lastt[nextt[k]] = lastt[k];
        int cnt = n-1,now = nextt[k];
        while(cnt)
        {
            int left = (k-1)%cnt;
            while(left--)	now = nextt[now];
            printf(" %d",now);
            nextt[lastt[now]] = nextt[now];
            lastt[nextt[now]] = lastt[now];
            now = nextt[now];
            cnt--;
        }
        putchar('\n');
    }
	return 0;
}
