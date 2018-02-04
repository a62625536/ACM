#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define LL long long
using namespace std;

LL PowerMod(LL a, LL b, LL c)
{
    LL ans = 1;
    a = a % c;
    while(b)
    {
        if(b&1) ans = (ans*a)%c;
        b = b>>1;
        a = (a*a)%c;
    }
    return ans;
}

int euler(int n)
{
    int res = n,a = n;
    for(int i = 2;i*i <= a;i++)
    {
        if(a%i == 0)
        {
            res = res/i*(i-1);
            while(a%i == 0)    a /= i;
        }
    }
    if(a > 1)    res = res/a*(a-1);
    return res;
}

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    int p,q;
    while(~scanf("%d%d",&p,&q))
    {
        q /= gcd(p,q);
        while(q%2 == 0)  q /= 2;
        while(q%5 == 0)  q /= 5;
        if(q == 1)
        {
            printf("0\n");
            continue;
        }
        int x = euler(q),now = 1;
        int xx = sqrt(x),flag = 0;
        for(int i = 1;i <= xx;i++)
        {
            if(x%i) continue;
            if(PowerMod(10,i,q) == 1)
            {
                printf("%d\n",i);
                flag = 1;
                break;
            }
        }
        if(flag)    continue;
        for(int i = xx;i >= 1;i--)
        {
            if(x%i) continue;
            if(PowerMod(10,x/i,q) == 1)
            {
                printf("%d\n",x/i);
                break;
            }
        }
    }
    return 0;
}
