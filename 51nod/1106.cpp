#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

bool flag[35000] = {0};
int n,prime[4000],cnt = 0;

void init()
{

}
int main()
{
    prime[++cnt] = 2;
    for(int i = 3;i <= 17500;i += 2)
    {
        if(flag[i]) continue;
        for(int j = 2;j*i <= 35000;j++) flag[j*i] = 1;
    }
    for(int i = 3;i <= 35000;i += 2)
    {
        if(flag[i] == 0)    prime[++cnt] = i;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int endd = sqrt(n);
        int i;
        for(i = 1;prime[i] <= endd;i++)
        {
            if(n%prime[i] == 0) break;
        }
        if(prime[i] > endd)    printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
