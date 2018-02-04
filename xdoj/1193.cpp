#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a[100005];

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
        }
        int l = 1,r = n,ans = 0;
        long long sum1 = 0,sum2 = 0;
        while(l <= r)
        {
            if(l == r && sum1 == sum2)
            {
                ans++;
                break;
            }
            if(sum1 < sum2)
            {
                sum1 += a[l++];
            }
            else
            {
                sum2 += a[r--];
            }
            if(sum1 == sum2)    ans += 2;
        }
        if(sum1 != sum2)    ans++;
        printf("%d\n",ans);
    }
    return 0;
}
