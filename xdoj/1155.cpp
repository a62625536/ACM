#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long k,x,y,ans;

int main()
{
    while(~scanf("%lld%lld%lld",&k,&x,&y))
    {
        long long p = min(x,y);
        p = min(p,k-x+1);
        p = min(p,k-y+1);
        long long dis = x-p+y-p;
        if(x <= y)  ans = 4*(p-1)*(k-p+1)+1+dis;
        else    ans =  4*p*(k-p)+1-dis;
        printf("%lld\n",ans);
    }
    return 0;
}
