#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define X 20000005
using namespace std;

int sum[X+1];
int n;

int main()
{
    for(int i = 1;i*i <= X;i++)
    {
        int t = i*i;
        for(int j = t;j <= X;j += t) sum[j]++;
    }
    for(int i = 2;i <= X;i++)    sum[i] = (sum[i]+sum[i-1]);
    while(~scanf("%d",&n))
    {
        printf("%d\n",sum[n]);
    }
    return 0;
}
