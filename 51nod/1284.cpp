#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long n;

int main()
{
    scanf("%lld",&n);
    long long ans = n;
    ans -= n/2;
    ans -= n/3;
    ans -= n/5;
    ans -= n/7;
    ans += n/6;
    ans += n/10;
    ans += n/14;
    ans += n/15;
    ans += n/21;
    ans += n/35;
    ans -= n/30;
    ans -= n/70;
    ans -= n/42;
    ans -= n/105;
    ans += n/210;
    printf("%lld\n",ans);
    return 0;
}
