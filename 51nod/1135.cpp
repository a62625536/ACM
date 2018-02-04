#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;

int n,a[35000],cnt = 0;

LL qmod(LL a, LL b, LL c)
{
    LL ans = 1;
    a = a%c;
    while(b)
    {
        if(b&1)    ans = ans*a%c;
        b >>= 1;
        a = a*a%c;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    int endd = sqrt(n-1);
    for(int i = 2;i <= endd;i++)
    {
        if((n-1)%i == 0)    a[++cnt] = i;
    }
    for(int i = 2;i <= n-1;i++)
    {
        int j;
        for(j = 1;j <= cnt;j++)
        {
            if(qmod(i,a[j],n) == 1 || qmod(i,(n-1)/a[j],n) == 1)    break;
        }
        if(j == cnt+1)
        {
            printf("%d\n",i);
            return 0;
        }
    }
}
