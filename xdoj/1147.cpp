#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,l[100005],r[100005],ans[100005],s;

int main()
{
    while(~scanf("%d%d",&n,&s))
    {
        int sum1 = 0,sum2 = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            sum1 += l[i];
            sum2 += r[i];
        }
        if(s < sum1 || s > sum2)
        {
            printf("Xue Beng\n");
            continue;
        }
        int x = s-sum1;
        for(int i = n;i >= 1;i--)
        {
            ans[i] = x >= r[i]-l[i]?r[i]:l[i]+x;
            x -= ans[i]-l[i];
        }
        printf("%d",ans[1]);
        for(int i = 2;i <= n;i++)   printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
