#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,k,a[20005],b[20005];

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int ans = 0;
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
        for(int i = 1;i <= m;i++)   scanf("%d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        int j = 1;
        for(int i = 1;i <= n;i++)
        {
            while(b[j] <= a[i]+k)
            {
                if(a[i]-k <= b[j])
                {
                    ans++;
                    j++;
                    break;
                }
                j++;
            }
            if(j > m)   break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
