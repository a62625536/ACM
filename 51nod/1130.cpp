#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define PI acos(-1)
using namespace std;

int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)

    {
        scanf("%d",&n);
        printf("%lld\n",(long long)(log10(2*PI*n)/2+n*log10(n/exp(1)))+1);
    }
    return 0;
}
