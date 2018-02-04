#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int ans =0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)   ans += i*j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
