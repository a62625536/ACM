#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",x+y-1);
    }
    return 0;
}
