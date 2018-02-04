#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[200005],n,k;
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        int l = 0,sum = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
            for(int j = l;j < i;j++)
            {
                if(a[j] == a[i])
                {
                    l = j+1;
                    break;
                }
            }
            if(i-l+1 == k)
            {
                sum++;
                l++;
            }
        }
        printf("%d\n",sum);
     }
}
