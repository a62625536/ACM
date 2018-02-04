#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int endd = sqrt(n);
        int ans = endd*endd == n?-1:0;
        for(int i = 1;i <= endd;i++)
        {
            if(n%i == 0)    ans += 2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
