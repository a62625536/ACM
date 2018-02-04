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
        int t = sqrt((n-1)*2);
        if(t*(t+1)/2+1 == n)    printf("1\n");
        else    printf("0\n");
    }
    return 0;
}
