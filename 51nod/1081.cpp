#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,q;
long long a[50005] = {0};

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i] = a[i-1]+x;
    }
    scanf("%d",&q);
    while(q--)
    {
        int l,t;
        scanf("%d%d",&l,&t);
        printf("%lld\n",a[l+t-1]-a[l-1]);
    }
    return 0;
}
