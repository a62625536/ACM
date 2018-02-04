#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

map<long long,int> mp;
int n,k;
long long a[10005];

int main()
{
    a[0] = 0;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i] = a[i-1]+x;
        mp[a[i]]++;
    }
    for(int i = 0;i <= n;i++)
    {
        if(mp[a[i]+k])
        {
            for(int j = i;j <= n;j++)
            {
                if(a[j]-a[i] == k)
                {
                    printf("%d %d\n",i+1,j);
                    return 0;
                }
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
