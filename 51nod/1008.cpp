#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,p;

int main()
{
    scanf("%d%d",&n,&p);
    long long ans = 1;
    for(int i = 2;i <= n;i++)   ans = ans*i%p;
    printf("%lld\n",ans);
    return 0;
}
