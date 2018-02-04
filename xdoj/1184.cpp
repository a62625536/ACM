#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    while(~scanf("%d",&n))
    {
        int ans = 0,t;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&t);
            ans ^= t%3;
        }
        if(ans) printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
