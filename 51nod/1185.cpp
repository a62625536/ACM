#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;

LL tmp[3] = {618033988,749894848,204586834};
LL MOD = 1000000000;
LL m,n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        if(m < n)   swap(n, m);
        LL cha = m-n;
        LL ta = cha/MOD, tb = cha%MOD;
        LL tp = tb*tmp[2];
        tp = ta*tmp[2]+tb*tmp[1]+tp/MOD;
        tp = ta*tmp[1]+tb*tmp[0]+tp/MOD;
        tp = cha+ta*tmp[0]+tp/MOD;
        if(tp == n) printf("B\n");
        else    printf("A\n");
    }
    return 0;
}
