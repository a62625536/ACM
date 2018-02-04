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
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",a*b/gcd(a,b));
    return 0;
}
