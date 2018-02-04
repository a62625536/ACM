#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long a,b,c;

int main()
{
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    long long ans = 0;
    if(a >= b && a >= c)
    {
        a--;
        if(a > b)   ans += a-b;
        if(a > c)   ans += a-c;
    }
    else if(b >= a && b >= c)
    {
        b--;
        if(b > a)   ans += b-a;
        if(b > c)   ans += b-c;
    }
    else if(c >= a && c >= b)
    {
        c--;
        if(c > a)   ans += c-a;
        if(c > b)   ans += c-b;
    }
    printf("%I64d\n",ans);
    return 0;
}
