#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long a,b,x[15]= {0},y[15] = {0};

void f(long long t,long long tt,long long *x)
{
    long long n = t/10,m = t%10,ttt = n;
    for(int i = 1;i <= m;i++)   x[i] += tt;
    for(int i = 0;i <= 9;i++)   x[i] += n*tt;
    while(ttt)
    {
        x[ttt%10] += (m+1)*tt;
        ttt /= 10;
    }
    if(n)   f(n-1,tt*10,x);
}

int main()
{
    scanf("%lld%lld",&a,&b);
    f(a-1,1,x);
    f(b,1,y);
    for(int i = 0;i <= 9;i++)   printf("%lld\n",y[i]-x[i]);
    return 0;
}
