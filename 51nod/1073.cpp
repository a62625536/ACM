#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;

int main()
{
    scanf("%d%d",&n,&k);
    int x= 0;
    for(int i = 2;i <= n;i++)   x = (x+k)%i;
    printf("%d\n",x+1);
    return 0;
}
