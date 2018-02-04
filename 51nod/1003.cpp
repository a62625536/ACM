#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int ans = 0,now = 5;
    while(now <= n)
    {
        ans += n/now;
        now *= 5;
    }
    printf("%d\n",ans);
    return 0;
}
