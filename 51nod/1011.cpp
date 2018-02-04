#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%lld\n",gcd(a,b));
    return 0;
}
