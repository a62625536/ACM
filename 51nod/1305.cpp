#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int a1 = 0,a2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x == 1)  a1++;
        else if(x == 2) a2++;
    }
    long long ans = (long long)(n-1)*a1+a2*(a2-1)/2;
    printf("%lld\n",ans);
    return 0;
}
